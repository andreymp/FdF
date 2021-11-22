/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:03:09 by jobject           #+#    #+#             */
/*   Updated: 2021/11/22 18:05:49 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zoom(t_paint	*paint)
{
	paint->x *= 30;
	paint->y *= 30;
	paint->z *= 30;
	paint->xo *= 30;
	paint->yo *= 30;
	paint->zo *= 30;
}

void	init_beg(t_paint	*paint)
{
	paint->x += 400;
	paint->y += 400;
	paint->xo += 400;
	paint->yo += 400;
}

void	zero_init(t_paint	**paint)
{
	(*paint)->x = 0;
	(*paint)->xo = 0;
	(*paint)->y = 0;
	(*paint)->yo = 0;
	(*paint)->z = 0;
	(*paint)->zo = 0;
}

static void	iso(float	*x, float	*y, float z)
{
	float	old_x;
	float	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(ANGLE);
	*y = (old_x + old_y) * sin(ANGLE) - z;
}

void	do_iso(t_paint	*paint)
{
	iso(&paint->x, &paint->y, paint->z);
	iso(&paint->xo, &paint->yo, paint->zo);
}
