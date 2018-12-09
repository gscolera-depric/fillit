/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:41:47 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/26 14:02:37 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t num)
{
	unsigned char	*a;

	a = (unsigned char*)s1;
	while (num > 0)
	{
		*a = *(unsigned char *)s2;
		a++;
		s2++;
		num--;
	}
	return (s1);
}
