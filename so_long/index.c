/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:39 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 13:16:44 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_read(int j, const char *name)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file");
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * j + 1);
	map[i] = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		map[i + 1] = NULL;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (map);
}

t_long	init_map(const char *name)
{
	t_long	mapa;
	int		op;

	op = 0;
	mapa.map = NULL;
	mapa.lines = cuenta_archivo(name);
	if (mapa.lines > 3)
	{
		mapa.map = map_read(mapa.lines, name);
		mapa.columns = cuenta_cols(mapa.map[0]);
		check_start(&mapa);
		if (mapa.lines == mapa.columns)
			op = 1;
		if (check_map(mapa, mapa.map) == 1 || only_one(mapa, mapa.map) == 1
			|| op == 1 || valid_c(mapa, mapa.map) == 1
			|| prepare_flood(mapa, mapa.map) == 1)
			mapa.valido = 1;
		else
		{
			mapa.map = map_read(mapa.lines, name);
			mapa.valido = 0;
		}
	}
	return (mapa);
}

void	start(t_long mapa)
{
	if (mapa.map != NULL && mapa.valido != 1)
	{
		game_loop(&mapa);
		frees(&mapa);
	}
	else
	{
		if (mapa.map == NULL)
			ft_printf("%s\n",
				"Error\nEl mapa no cumple los requisitos. Introduzca otro");
		else
		{
			ft_printf("%s\n",
				"Error\nEl mapa no cumple los requisitos. Introduzca otro");
			free_map(&mapa);
		}
	}
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_long	mapa;

	if (argc != 2)
	{
		ft_printf("%s\n", "Error\nIntroduzca 1 mapa");
		return (0);
	}
	else
	{
		mapa = init_map(argv[1]);
		start(mapa);
	}
	system("leaks so_long");
	return (0);
}
