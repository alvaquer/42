/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:29:36 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/09 15:33:35 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(t_long *mapa)
{
	init_game_data(mapa);
	draw_map(mapa);
	mlx_key_hook(mapa->mlx, keyhook, mapa);
	mlx_loop_hook(mapa->mlx, hook, mapa);
	mlx_loop(mapa->mlx);
	mlx_terminate(mapa->mlx);
}

void	hook(void *param)
{
	t_long	*mapa;

	mapa = param;
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_long			*mapa;

	mapa = param;
	if (mlx_is_key_down(mapa->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mapa->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		function_move(mapa, 0, 1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		function_move(mapa, -1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		function_move(mapa, 0, -1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		function_move(mapa, 1, 0);
}
