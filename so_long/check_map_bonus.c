/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:05:56 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 11:06:10 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_long mapa, char **mapatemp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mapa.lines)
	{
		j = 0;
		if (i == 0 || i == (mapa.lines - 1))
		{
			while (mapatemp[i][j] != '\n' && mapatemp[i][j] != '\0')
			{
				if (mapatemp[i][j] != '1')
					return (1);
				j++;
			}
		}
		if (mapatemp[i][0] != '1' || mapatemp[i][mapa.columns - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	only_one(t_long mapa, char **mapatemp)
{
	if (count_c(mapa, mapatemp) == 1 || only_one_p(mapa, mapatemp) == 1)
		return (1);
	return (0);
}

int	valid_c(t_long mapa, char **mapatemp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapa.lines)
	{
		j = 0;
		while (j < mapa.columns)
		{
			if (mapa.map[i][j] != 'E' && mapatemp[i][j] != 'P'
				&& mapatemp[i][j] != 'C' && mapatemp[i][j] != '0'
				&& mapatemp[i][j] != '1' && mapatemp[i][j] != 'X')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	prepare_flood(t_long mapa, char **mapatemp)
{
	t_position	p;
	t_position	t;

	p.x = mapa.player_pos_x;
	p.y = mapa.player_pos_y;
	t.y = mapa.columns;
	t.x = mapa.lines;
	flood_fill(mapatemp, t, p.x, p.y);
	if (check_flood(mapa) == 0)
	{
		free_flood(mapa, mapatemp);
		return (0);
	}
	else
	{
		free_flood(mapa, mapatemp);
		return (1);
	}
}