/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:46:35 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/29 13:09:25 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_matrix(size_t rows, size_t colums, char c)
{
	char		**tmp;
	size_t		i;
	size_t		j;

	if (!(tmp = (char**)malloc(sizeof(char*) * (rows + 1))))
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		if (!(tmp[i] = ft_strnew(colums)))
		{
			ft_free_array(tmp);
			return (NULL);
		}
		j = 0;
		while (j < colums)
			tmp[i][j++] = c;
	}
	tmp[i] = 0;
	return (tmp);
}
