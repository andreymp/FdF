/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:04:00 by jobject           #+#    #+#             */
/*   Updated: 2021/11/22 15:22:40 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	eexit(int zero)
{
	(void) zero;
	exit(EXIT_FAILURE);
}

int	esc(int keyhook)
{
	if (keyhook == ESC)
		exit(EXIT_FAILURE);
	return (keyhook);
}

void	error_message(char	*message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	free_mem(char	**strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	init_zo(t_paint	*p, t_list	*lst)
{
	while (lst)
	{
		if (lst->x == p->xo && lst->y == p->yo)
			p->zo = lst->z;
		if (lst->x == p->x && lst->y == p->y)
			p->z = lst->z;
		lst = lst->next;
	}
}
