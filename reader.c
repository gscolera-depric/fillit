/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:22:23 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/09 19:23:48 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_coords(char *buff)
{
	int i;
	int block;
	int touch;

	i = -1;
	block = 0;
	touch = 0;
	while (++i < 20)
	{
		if (buff[i] == '#')
		{
			block++;
			if (i / 5 < 3 && buff[i + 5] == '#')
				touch++;
			if (buff[i + 1] == '#')
				touch++;
		}
	}
	if ((touch != 3 && touch != 4) || block != 4)
		return (1);
	return (0);
}

static int		check_line(char *buff, int ret)
{
	int i;

	i = -1;
	if (ret == 21 && buff[20] != '\n')
		return (1);
	if (ret < 20)
		return (-1);
	while (++i < ret - 1)
	{
		if (i == 4 || i == 9 || i == 14 | i == 19)
		{
			if (buff[i] != '\n')
				return (-1);
		}
		else
		{
			if (buff[i] != '.' && buff[i] != '#')
				return (-1);
		}
	}
	if (check_coords(buff) == 1)
		return (-1);
	return (0);
}

static	TET		get_valid_tetrinomo(char *buff, int ret)
{
	TET unit;
	int i;
	int block;

	i = -1;
	block = 0;
	while (++i < ret)
	{
		if (buff[i] == '#')
		{
			unit.x[block] = i / 5;
			unit.y[block++] = i % 5;
		}
	}
	return (unit);
}

static TET		cut_coords(TET unit, int count)
{
	int maxx;
	int maxy;
	int minx;
	int miny;
	int i;

	i = 4;
	maxx = 0;
	maxy = 0;
	minx = 0;
	miny = 0;
	while (--i >= 0)
	{
		unit.x[i] -= unit.x[0];
		unit.y[i] -= unit.y[0];
		maxx = (unit.x[i] > maxx) ? unit.x[i] : maxx;
		maxy = (unit.y[i] > maxy) ? unit.y[i] : maxy;
		minx = (unit.x[i] < minx) ? unit.x[i] : minx;
		miny = (unit.y[i] < miny) ? unit.y[i] : miny;
	}
	unit.height = maxx - minx + 1;
	unit.length = maxy - miny + 1;
	unit.id = count + 65;
	return (unit);
}

int				reader(int fd, TET unit[])
{
	char	buff[21];
	int		ret;
	int		count;

	count = 0;
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		if (count == MAX_TET)
			return (-1);
		if (check_line(buff, ret) == -1)
			return (-1);
		unit[count] = get_valid_tetrinomo(buff, ret);
		unit[count] = cut_coords(unit[count], count);
		count++;
		if (ret == 20)
			break ;
	}
	if (ret != 20)
		return (-1);
	return (count);
}
