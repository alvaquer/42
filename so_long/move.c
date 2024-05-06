/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:50:14 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 10:57:06 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	function_move(t_long *mapa, int x, int y)
{
	t_position	pos;

	pos.x = mapa->player_pos_x + x;
	pos.y = mapa->player_pos_y + y;
	if ((pos.x >= 0 && pos.x <= mapa->columns)
		|| (pos.y >= 0 && pos.y <= mapa->lines))
	{
		if (is_valid_move(mapa, pos) == 1)
		{
			before_move (mapa, mapa->player_pos_x, mapa->player_pos_y);
			move (mapa, pos);
			mapa->player_pos_x = pos.x;
			mapa->player_pos_y = pos.y;
			mapa->moves ++;
			ft_putstr_fd("Player moves: ", 1);
			ft_putnbr_fd(mapa->moves, 1);
			write(1, "\n", 1);
		}
	}
}

void	move(t_long *mapa, t_position pos)
{
	if (mapa->map[pos.y][pos.x] == 'C')
	{
		mlx_image_to_window(mapa->mlx, mapa->tiles->floor_img,
			(pos.x * TILE), (pos.y * TILE));
		mapa->ncollect ++;
		ft_printf("Hay %d objetos en total. Tienes %d\n",
			mapa->collectionables, mapa->ncollect);
		if (mapa->ncollect == mapa->collectionables)
			mlx_image_to_window(mapa->mlx, mapa->tiles->exit_img[1],
				(mapa->exit_pos->x * TILE), (mapa->exit_pos->y * TILE));
	}
	else if (mapa->map[pos.y][pos.x] == 'E'
		&& mapa->ncollect == mapa->collectionables)
	{
		ft_printf("Has ganado\n");
		mlx_close_window(mapa->mlx);
	}
	mlx_image_to_window(mapa->mlx, mapa->tiles->player_img[0],
		(pos.x * TILE), (pos.y * TILE));
}

void	before_move(t_long *mapa, int x, int y)
{
	if (mapa->map[y][x] == '0'
		|| mapa->map[y][x] == 'C' || mapa->moves == 0)
	{
		mapa->map[y][x] = '0';
		mlx_image_to_window(mapa->mlx, mapa->tiles->floor_img,
			(x * TILE), (y * TILE));
	}
	else if (mapa->map[y][x] == 'E')
	{
		if (mapa->ncollect != mapa->collectionables)
		{
			mlx_image_to_window(mapa->mlx, mapa->tiles->exit_img[0],
				(mapa->exit_pos->x * TILE), (mapa->exit_pos->y * TILE));
		}
	}
}

int	is_valid_move(t_long *mapa, t_position pos)
{
	if (mapa->map[pos.y][pos.x] != '1' && mapa->map[pos.y][pos.x] != 'X')
		return (1);
	else
		return (0);
}
