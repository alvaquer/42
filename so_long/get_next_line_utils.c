/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:17:22 by alvaquer          #+#    #+#             */
/*   Updated: 2023/12/28 17:59:08 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int a)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)a)
		{
			return ((char *)str);
		}
		str++;
	}
	if ((unsigned char)a == '\0')
		return ((char *)str);
	return (0);
}

/* La función `ft_strchr` busca la primera
 ocurrencia del carácter `a` en la cadena `str`. */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(k + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

/* La función `ft_strjoin` concatena dos cadenas
 `s1` y `s2` en una nueva cadena. */

size_t	ft_strlen(const char *cadena)
{
	int	i;

	i = 0;
	while (cadena[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	*ft_memcpy(void *dest, const void *origen, size_t num)
{
	size_t	i;
	char	*str;
	char	*str1;

	str = (char *)dest;
	str1 = (char *)origen;
	if (!dest && !origen)
		return (0);
	i = 0;
	while (i < num)
	{
		*str = *str1;
		i++;
		str++;
		str1++;
	}
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	s2 = (char *)ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
