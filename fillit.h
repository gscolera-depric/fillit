/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:39:36 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/09 19:31:34 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TET t_etrinomo
# define MAP t_map
# define IN 1
# define OUT 0
# define MAX_TET 26

# include "libft/libft.h"

typedef struct	s_etrinomo
{
	int					x[4];
	int					y[4];
	char				id;
	int					height;
	int					length;
}				t_etrinomo;

typedef struct	s_map
{
	char	**line;
	int		size;
	int		amount;
	int		x;
	int		y;
	int		in;
	int		stat;
}				t_map;

int				reader(int fd, TET unit[]);
MAP				find_solution(TET unit[], MAP map);

#endif
