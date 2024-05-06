/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:30:32 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/09 15:34:15 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_start(t_long *mapa)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapa->lines)
	{
		j = 0;
		while (j < mapa->columns)
		{
			if (mapa->map[i][j] == 'P')
			{
				mapa->player_pos_x = j;
				mapa->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_exit(t_long *mapa)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapa->lines)
	{
		j = 0;
		while (j < mapa->columns)
		{
			if (mapa->map[i][j] == 'E')
			{
				mapa->exit_pos = malloc(sizeof(t_position));
				mapa->exit_pos->x = j;
				mapa->exit_pos->y = i;
			}
			j++;
		}
		i++;
	}
}

void	init_game_data(t_long *mapa)
{
	int	width;
	int	height;

	width = TILE * mapa->columns;
	height = TILE * mapa->lines;
	check_exit(mapa);
	mapa->ncollect = 0;
	mapa->moves = 0;
	mapa->collectionables = count_collect(mapa);
	mapa->mlx = mlx_init(width, height, "so_long", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
}

int	count_collect(t_long *mapa)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (i < mapa->lines)
	{
		j = 0;
		while (j < mapa->columns)
		{
			if (mapa->map[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}
