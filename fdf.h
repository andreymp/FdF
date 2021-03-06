/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:07:11 by jobject           #+#    #+#             */
/*   Updated: 2021/11/22 18:07:54 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define HEIGHT 1000
# define WIDTH 1000

# define ESC 53

# define ANGLE 0.523599

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	void	*image;
	char	*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}				t_win;

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
}				t_map;

typedef struct s_paint
{
	float	x;
	float	y;
	float	z;
	float	xo;
	float	yo;
	float	zo;
}				t_paint;

int		esc(int keyhook);
int		eexit(int zero);
void	error_message(char	*message);
void	check(int argc, char	**argv);
void	win_init(t_win	*win);
void	free_mem(char	**strs);
int		get_size(char	**strs);
t_list	*make_coo_list(char	*filename, t_map *map);
void	draw(t_list	*lst, t_win	*win, t_map	*map);
void	init_zo(t_paint	*p, t_list	*lst);
void	init_zoom(t_paint	*paint);
void	init_beg(t_paint	*paint);
void	zero_init(t_paint	**paint);
void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
void	do_init_image(t_win *win);
void	do_iso(t_paint	*paint);

#endif