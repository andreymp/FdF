/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:02:53 by jobject           #+#    #+#             */
/*   Updated: 2021/11/22 15:28:57 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	del(int x, int y, int z)
{
	x = 0;
	y = 0;
	z = 0;
}

int	main(int argc, char	**argv)
{
	t_win	win;
	t_list	*lst;
	t_map	map;

	check(argc, argv);
	lst = make_coo_list(argv[1], &map);
	win_init(&win);
	draw(lst, &win, &map);
	if (lst)
		ft_lstclear(&lst, del);
	mlx_loop(win.mlx);
	return (0);
}
