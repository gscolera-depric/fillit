/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:23:12 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/21 14:58:45 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char *p1;
	const unsigned char *p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*(p1 + i) - *(p2 + i) != 0)
			return ((int)*(p1 + i) - *(p2 + i));
		i++;
	}
	return (0);
}
