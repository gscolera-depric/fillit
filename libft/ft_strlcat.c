/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:43:27 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/21 20:04:40 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char		*s;
	char			*d;
	size_t			len_dest;
	size_t			len;

	len = size;
	s = src;
	d = dst;
	while (len-- && *d)
		d++;
	len_dest = d - dst;
	len = (size - len_dest);
	if (len == 0)
		return (len_dest + ft_strlen(src));
	while (*s)
	{
		if (len != 1)
		{
			*d++ = *s;
			len--;
		}
		s++;
	}
	*d = '\0';
	return (len_dest + (s - src));
}
