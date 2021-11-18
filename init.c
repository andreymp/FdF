/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:01:38 by jobject           #+#    #+#             */
/*   Updated: 2021/11/19 01:02:35 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	check(int argc, char	**argv)
{
	if (argc != 2)
		error_message("ERROR: Wrong number of argumnets.");
	if (ft_strlen(argv[1]) < 5)
		error_message("ERROR: Wrong file name.");
	if (argv[1][ft_strlen(argv[1]) - 1] != 'f'
		&& argv[1][ft_strlen(argv[1]) - 2] != 'd'
		&& argv[1][ft_strlen(argv[1]) - 3] != 'f'
		&& argv[1][ft_strlen(argv[1]) - 4] != '.')
		error_message("ERROR: Wrong file name.");
}

static int	ft_size(char	*filename, t_map	*mapa)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(filename, O_RDONLY);
	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		size++;
		free(line);
	}
	mapa->y = size;
	close(fd);
	return (size);
}

static t_map	get_str_map(char	*filename)
{
	t_map	mapa;
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message("ERROR: Unable to open file");
	i = 0;
	mapa.map = (char **) malloc(sizeof(char *)
			* (ft_size(filename, &mapa) + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mapa.map[i++] = ft_strdup(line);
		free(line);
	}
	mapa.y = i - 1;
	mapa.map[i] = NULL;
	close(fd);
	return (mapa);
}

static void	get_coo(t_list	**lst, char	**nums, int y)
{
	int		i;
	t_list	*cur;

	i = 0;
	while (nums[i])
	{
		cur = (t_list *) malloc (sizeof(t_list));
		cur->x = i;
		cur->y = y;
		cur->z = ft_atoi(nums[i]);
		cur->next = NULL;
		i++;
		ft_lstadd_back(lst, cur);
	}
}

t_list	*make_coo_list(char	*filename, t_map *map)
{
	t_list	*lst;
	int		i;

	*map = get_str_map(filename);
	i = 0;
	lst = NULL;
	while (map->map[i])
	{
		get_coo(&lst, ft_split(map->map[i], ' '), i);
		i++;
	}
	free_mem(map->map);
	return (lst);
}
