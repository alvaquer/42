/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:28:22 by alvaquer          #+#    #+#             */
/*   Updated: 2024/01/24 14:35:28 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_line(char *tempbuf)
{
	char	*temp;
	int		i;

	i = 0;
	if (!tempbuf || tempbuf[i] == '\0')
		return (NULL);
	while (tempbuf[i] != '\0' && tempbuf[i] != '\n')
		i++;
	if (tempbuf[i] == '\n')
		i++;
	temp = (char *)malloc((i + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (tempbuf[i] != '\0' && tempbuf[i] != '\n')
	{
		temp[i] = tempbuf[i];
		i++;
	}
	if (tempbuf[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

static char	*clean_line(char *tempbuf)
{
	unsigned long	i;
	int				j;
	char			*copy;

	i = 0;
	j = 0;
	while (tempbuf[i] != '\0' && tempbuf[i] != '\n')
		i++;
	if (tempbuf[i] == '\0')
	{
		free(tempbuf);
		return (NULL);
	}
	if (tempbuf[i] == '\n')
		i++;
	copy = (char *)malloc(ft_strlen(tempbuf) + 1 - i);
	if (copy == NULL)
		return (NULL);
	while (tempbuf[i] != '\0')
		copy[j++] = tempbuf[i++];
	copy[j] = '\0';
	free(tempbuf);
	return (copy);
}

static char	*read_line(char *init, char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	if (init == NULL)
		init = ft_strdup("");
	while (!ft_strchr(init, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(init);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = init;
		init = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (init);
}

char	*get_next_line(int fd)
{
	static char	*init;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(init);
		init = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	init = read_line(init, buffer, fd);
	free(buffer);
	buffer = check_line(init);
	init = clean_line(init);
	return (buffer);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
} */

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	close(fd);
	return (0);
}
