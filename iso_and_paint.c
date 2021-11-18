/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_and_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:08:53 by jobject           #+#    #+#             */
/*   Updated: 2021/11/19 01:09:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->size_line + x * (win->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

void	do_init_image(t_win *win)
{
	if (win->image)
		mlx_destroy_image(win->mlx, win->image);
	win->image = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->addr = mlx_get_data_addr(win->image, &win->pixel_bits,
			&win->size_line, &win->endian);
}
