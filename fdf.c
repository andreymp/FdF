/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:04:39 by jobject           #+#    #+#             */
/*   Updated: 2021/11/19 01:09:38 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_init(t_win	*win)
{
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "fdf");
	mlx_hook(win->mlx_win, 17, 0, eexit, win);
	mlx_hook(win->mlx_win, 2, 1L << 0, esc, win);
}

void	iso(int	*x, int	*y, int z)
{
	*x = (*x - *y) * cos(0.77);
	*y = (*x + *y) * sin(0.77) - z;
}

void	draw_line1(t_list	*lst, t_paint	p, t_win	*win)
{
	float	i;
	float	step;

	i = 0;
	init_zo(&p, lst);
	init_zoom(&p);
	do_iso(&p);
	init_beg(&p);
	step = 1 / (fmaxf(abs(p.xo - p.x), abs(p.yo - p.y)) * 3);
	while (i <= 1)
	{
		p.x += (i * (p.xo - p.x));
		p.y += (i * (p.yo - p.y));
		if (p.x < WIDTH && p.x >= 0 && p.y < HEIGHT && p.y >= 0)
		{
			if (p.zo > 0)
				my_mlx_pixel_put(win, p.x, p.y, 0x006effff);
			else
				my_mlx_pixel_put(win, p.x, p.y, 0x00ff1694);
		}
		i += step;
	}
}

void	draw_line2(t_list	*lst, t_paint	p, t_win	*win)
{
	float	i;
	float	step;

	i = 0;
	init_zo(&p, lst);
	init_zoom(&p);
	do_iso2(&p);
	init_beg(&p);
	step = 9 / (fmaxf(abs(p.xo - p.x), abs(p.yo - p.y)) * 100);
	while (i <= 1)
	{
		p.x += (i * (p.xo - p.x));
		p.y += (i * (p.yo - p.y));
		p.z += (i * (p.zo - p.z));
		if (p.x < WIDTH && p.x >= 0 && p.y < HEIGHT && p.y >= 0)
		{
			if (p.zo != 0)
				my_mlx_pixel_put(win, p.x, p.y, 0x006effff);
		}
		i += step;
	}
}

void	draw(t_list	*lst, t_win	*win, t_map	*map)
{
	t_paint	*p;

	p = (t_paint *) malloc (sizeof(t_paint));
	zero_init(&p);
	do_init_image(win);
	p->y = 0;
	map->x = ft_lstsize(lst) / map->y - 1;
	while (lst && p->y < map->y)
	{
		p->x = 0;
		while (lst && p->x < map->x)
		{
			if (p->x < map->x - 1)
			{
				p->xo = p->x + 1;
				p->yo = p->y;
				draw_line1(lst, *p, win);
				draw_line2(lst, *p, win);
			}
			if (p->y < map->y - 1)
			{
				p->xo = p->x;
				p->yo = p->y + 1;
				draw_line1(lst, *p, win);
				draw_line2(lst, *p, win);
			}
			lst = lst->next;
			p->x++;
		}
		lst = lst->next;
		p->y++;
	}
	free (p);
	mlx_put_image_to_window(win->mlx,
		win->mlx_win, win->image, 0, 0);
}
