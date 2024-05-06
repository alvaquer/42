/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:37:23 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/12 11:20:36 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf/libftprintf/ft_printf.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SPRITE 16
# define TILE 32

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*player[3];
	mlx_texture_t	*exit[3];
	mlx_texture_t	*enemy;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*collect_img;
	mlx_image_t		*player_img[3];
	mlx_image_t		*exit_img[3];
	mlx_image_t		*enemy_img;

}					t_texture;

typedef struct s_long
{
	char			**map;
	int				lines;
	int				columns;
	int				moves;
	int				player_pos_x;
	int				player_pos_y;
	int				valido;
	int				ncollect;
	int				collectionables;
	mlx_t			*mlx;
	t_position		*player_movement[5];
	t_texture		*tiles;
	t_position		*exit_pos;
}					t_long;

int			check_map(t_long mapa, char **mapatemp);

int			only_one(t_long mapa, char **mapatemp);

int			valid_c(t_long mapa, char **mapatemp);

int			prepare_flood(t_long mapa, char **mapatemp);

void		flood_fill(char **mapa, t_position t, int x, int y);

int			check_flood(t_long mapa);

void		free_flood(t_long mapa, char **map);

t_long		*fix_start(t_long mapa);

int			cuenta_archivo(const char *name);

int			cuenta_cols(char *mapa);

void		draw_map(t_long *mapa);

void		draw_tiles(t_long *mapa, int i, int j);

void		init_tile_textures(t_long *mapa);

void		init_idle_texture(t_long *mapa);

char		**map_read(int j, const char *name);

t_long		init_map(const char *name);

void		game_loop(t_long *mapa);

void		hook(void *param);

void		keyhook(mlx_key_data_t keydata, void *param);

void		init_game_data(t_long *mapa);

void		init_movements(t_long *mapa);

void		ft_putstr_fd(char *s, int fd);

void		function_move(t_long *mapa, int x, int y);

void		*ft_memset(void *ptr, int valor, size_t num);

void		*ft_memcpy(void *dest, const void *origen, size_t num);

void		ft_putnbr_fd(int n, int fd);

void		ft_putchar_fd(char c, int fd);

void		delete_tile_textures(t_long *mapa);

int			is_valid_move(t_long *mapa, t_position position);

void		load_tile_images(t_long *mapa);

char		*ft_itoa(int n);

char		*ft_strjoin(char const *s1, char const *s2);

void		move(t_long *mapa, t_position pos);

void		before_move(t_long *mapa, int x, int y);

int			count_c(t_long mapa, char **mapatemp);

int			only_one_p(t_long mapa, char **mapatemp);

void		check_exit(t_long *mapa);

void		check_start(t_long *mapa);

void		frees(t_long *mapa);

void		free_map(t_long *mapa);

void		draw_tiles_p(t_long *mapa, int i, int j);

int			count_collect(t_long *mapa);

void		start(t_long mapa);

#endif