/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:06:08 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/27 12:21:26 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		sign;

	d = dst;
	s = src;
	sign = c;
	while (n-- > 0)
	{
		*d = *s;
		if (*s == sign)
			return ((void*)++d);
		s++;
		d++;
	}
	return (NULL);
}
