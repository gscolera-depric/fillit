/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:47:47 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/09 21:08:53 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

MAP	get_map(int amount, TET unit[])
{
	MAP map;
	int i;

	i = -1;
	map.x = 0;
	map.y = 0;
	map.in = 0;
	map.stat = 0;
	map.amount = amount;
	map.size = 1;
	while (map.size * map.size < map.amount * 4)
		map.size++;
	while (++i < map.amount)
	{
		map.size = (map.size > unit[i].height) ? map.size : unit[i].height;
		map.size = (map.size > unit[i].length) ? map.size : unit[i].length;
	}
	map.line = ft_matrix(map.size, map.size, '.');
	return (map);
}

int	main(int ac, char **av)
{
	TET unit[MAX_TET];
	int fd;
	MAP map;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [source file]");
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	map.amount = reader(fd, unit);
	if (map.amount == -1)
	{
		ft_putendl("error");
		close(fd);
		exit(0);
	}
	map = get_map(map.amount, unit);
	map = find_solution(unit, map);
	ft_print_array(map.line);
	ft_free_array(map.line);
	return (0);
}
