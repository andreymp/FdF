/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:03:09 by jobject           #+#    #+#             */
/*   Updated: 2021/11/19 01:09:45 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zoom(t_paint	*paint)
{
	paint->x *= 35;
	paint->y *= 35;
	paint->z *= 25;
	paint->xo *= 35;
	paint->yo *= 35;
	paint->zo *= 25;
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

void	do_iso(t_paint	*paint)
{
	iso(&paint->x, &paint->y, paint->zo);
	iso(&paint->xo, &paint->yo, paint->zo);
}

void	do_iso2(t_paint	*paint)
{
	iso(&paint->x, &paint->y, paint->zo);
	iso(&paint->xo, &paint->yo, paint->z);
}
