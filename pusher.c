/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:33:03 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/09 19:22:50 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	put(TET unit, MAP map, int x, int y)
{
	if (x + unit.x[0] >= map.size || y + unit.y[0] >= map.size
	|| map.line[x + unit.x[0]][y + unit.y[0]] != '.')
		return (-1);
	if (x + unit.x[1] >= map.size || y + unit.y[1] >= map.size
	|| map.line[x + unit.x[1]][y + unit.y[1]] != '.')
		return (-1);
	if (x + unit.x[2] >= map.size || y + unit.y[2] >= map.size
	|| map.line[x + unit.x[2]][y + unit.y[2]] != '.')
		return (-1);
	if (x + unit.x[3] >= map.size || y + unit.y[3] >= map.size
	|| map.line[x + unit.x[3]][y + unit.y[3]] != '.')
		return (-1);
	map.line[x + unit.x[0]][y + unit.y[0]] = unit.id;
	map.line[x + unit.x[1]][y + unit.y[1]] = unit.id;
	map.line[x + unit.x[2]][y + unit.y[2]] = unit.id;
	map.line[x + unit.x[3]][y + unit.y[3]] = unit.id;
	return (0);
}

static int	delete(TET unit, MAP map)
{
	while (map.x < map.size)
	{
		if (map.line[map.x][map.y] == unit.id)
		{
			map.line[map.x][map.y] = '.';
			map.line[map.x + unit.x[1]][map.y + unit.y[1]] = '.';
			map.line[map.x + unit.x[2]][map.y + unit.y[2]] = '.';
			map.line[map.x + unit.x[3]][map.y + unit.y[3]] = '.';
			return (0);
		}
		map.y = (map.y < map.size - 1) ? map.y + 1 : 0;
		map.x = (map.y == 0) ? map.x + 1 : map.x;
	}
	return (-1);
}

static int	push(TET unit[], MAP map)
{
	int x;
	int y;

	x = -1;
	while (++x < map.size)
	{
		y = -1;
		while (++y < map.size)
		{
			while (put(unit[map.in], map, x, y) == 0)
			{
				map.in++;
				x = 0;
				y = 0;
			}
		}
	}
	return (map.in);
}

static int	move(TET unit[], MAP map)
{
	map.stat = map.in;
	while (map.stat < map.amount)
		delete(unit[map.stat++], map);
	map.stat = IN;
	while (map.x < map.size)
	{
		if (map.stat == OUT)
			if (put(unit[map.in - 1], map, map.x, map.y) == 0)
				return (0);
		if (unit[map.in - 1].id == map.line[map.x][map.y])
		{
			delete(unit[map.in - 1], map);
			map.stat = OUT;
		}
		map.y = (map.y < map.size - 1) ? map.y + 1 : 0;
		map.x = (map.y == 0) ? map.x + 1 : map.x;
	}
	return (-2);
}

MAP			find_solution(TET unit[], MAP map)
{
	map.in = push(unit, map);
	if (map.in == map.amount)
		return (map);
	while (map.in != map.amount)
	{
		if (move(unit, map) == 0)
			map.in = push(unit, map);
		else
			map.in--;
		if (map.in == -1)
		{
			map.size++;
			map.in = 0;
			ft_free_array(map.line);
			map.line = ft_matrix(map.size, map.size, '.');
			find_solution(unit, map);
			return (map);
		}
	}
	return (map);
}
