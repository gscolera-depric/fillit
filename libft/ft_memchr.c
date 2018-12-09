/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:50:28 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 15:14:29 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*p;

	while (n--)
	{
		if ((unsigned char)c == *(unsigned char*)(s))
		{
			p = (void*)s;
			return (p);
		}
		s++;
	}
	return (NULL);
}
