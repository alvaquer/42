/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:41:11 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/09 13:48:39 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_long *mapa)
{
	int	i;
	int	j;

	i = 0;
	load_tile_images(mapa);
	while (i < mapa->lines)
	{
		j = 0;
		while (j < mapa->columns)
		{
			draw_tiles(mapa, i, j);
			j++;
		}
		i++;
	}
}

void	draw_tiles(t_long *mapa, int i, int j)
{
	if (mapa->map[i][j] == '1')
		mlx_image_to_window(mapa->mlx,
			mapa->tiles->wall_img, (j * TILE), (i * TILE));
	else if (mapa->map[i][j] == '0')
		mlx_image_to_window(mapa->mlx,
			mapa->tiles->floor_img, (j * TILE), (i * TILE));
	else if (mapa->map[i][j] == 'P')
		draw_tiles_p(mapa, i, j);
	else if (mapa->map[i][j] == 'E')
		mlx_image_to_window(mapa->mlx,
			mapa->tiles->exit_img[0], (j * TILE), (i * TILE));
	else if (mapa->map[i][j] == 'X')
	{
		mlx_image_to_window(mapa->mlx, mapa->tiles->floor_img,
			(j * TILE), (i * TILE));
		mlx_image_to_window(mapa->mlx,
			mapa->tiles->enemy_img, (j * TILE), (i * TILE));
	}
	else if (mapa->map[i][j] == 'C')
	{
		mlx_image_to_window(mapa->mlx, mapa->tiles->floor_img,
			(j * TILE), (i * TILE));
		mlx_image_to_window(mapa->mlx, mapa->tiles->collect_img,
			(j * TILE), (i * TILE));
	}
}

void	load_tile_images(t_long *mapa)
{
	t_texture	*tiles;
	mlx_t		*mlx;

	mapa->tiles = (t_texture *)malloc(sizeof(t_texture));
	mlx = mapa->mlx;
	tiles = mapa->tiles;
	tiles->floor = mlx_load_png("images/tiles/floor/0.png");
	tiles->wall = mlx_load_png("images/tiles/wall/0.png");
	tiles->player[0] = mlx_load_png("images/player/idle/right/a.png");
	tiles->player[1] = mlx_load_png("images/player/idle/right/b.png");
	tiles->player[2] = NULL;
	tiles->exit[0] = mlx_load_png("images/tiles/other/33.png");
	tiles->exit[1] = mlx_load_png("images/tiles/other/34.png");
	tiles->exit[2] = NULL;
	tiles->collect = mlx_load_png("images/tiles/other/35.png");
	tiles->enemy = mlx_load_png("images/enemy/idle/c.png");
	tiles->enemy_img = mlx_texture_to_image(mlx, tiles->enemy);
	tiles->floor_img = mlx_texture_to_image(mlx, tiles->floor);
	tiles->wall_img = mlx_texture_to_image(mlx, tiles->wall);
	tiles->collect_img = mlx_texture_to_image(mlx, tiles->collect);
	tiles->exit_img[0] = mlx_texture_to_image(mlx, tiles->exit[0]);
	tiles->exit_img[1] = mlx_texture_to_image(mlx, tiles->exit[1]);
	tiles->player_img[0] = mlx_texture_to_image(mlx, tiles->player[0]);
	tiles->player_img[1] = mlx_texture_to_image(mlx, tiles->player[1]);
	delete_tile_textures(mapa);
}

void	delete_tile_textures(t_long *mapa)
{
	t_texture	*tiles;

	tiles = mapa->tiles;
	mlx_delete_texture(tiles->floor);
	mlx_delete_texture(tiles->wall);
	mlx_delete_texture(tiles->exit[0]);
	mlx_delete_texture(tiles->exit[1]);
	mlx_delete_texture(tiles->player[0]);
	mlx_delete_texture(tiles->player[1]);
}

void	draw_tiles_p(t_long *mapa, int i, int j)
{
	mlx_image_to_window(mapa->mlx, mapa->tiles->floor_img,
		(j * TILE), (i * TILE));
	mlx_image_to_window(mapa->mlx,
		mapa->tiles->player_img[0], (j * TILE), (i * TILE));
}
