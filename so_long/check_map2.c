/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:23:19 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 11:43:08 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cuenta_archivo(const char *name)
{
	int		i;
	int		fd;
	char	*prueba;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error al abrir el archivo\n");
		return (1);
	}
	prueba = get_next_line(fd);
	while ((prueba) != NULL)
	{
		i++;
		free(prueba);
		prueba = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	cuenta_cols(char *mapa)
{
	int	i;

	i = 0;
	while (mapa[i] != '\0')
		i++;
	return (i - 1);
}

void	flood_fill(char **mapa, t_position t, int x, int y)
{
	if (y < 0 || y >= t.x || x < 0 || x >= t.y || mapa[y][x] == '1'
		|| mapa[y][x] == 'F' || mapa[y][x] == 'X')
		return ;
	mapa[y][x] = 'F';
	flood_fill(mapa, t, x - 1, y);
	flood_fill(mapa, t, x + 1, y);
	flood_fill(mapa, t, x, y - 1);
	flood_fill(mapa, t, x, y + 1);
}

int	check_flood(t_long mapa)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapa.lines)
	{
		j = 0;
		while (j < mapa.columns)
		{
			if (mapa.map[i][j] == 'E' || mapa.map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_flood(t_long mapa, char **map)
{
	int	i;

	i = 0;
	while (i < mapa.lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
