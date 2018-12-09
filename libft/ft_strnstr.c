/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:05:37 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 15:37:43 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t leng)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < leng)
	{
		j = 0;
		while (haystack[i] && haystack[i] == needle[j] && i < leng)
		{
			j++;
			i++;
		}
		if (j == len)
			return (&(((char*)haystack)[i - j]));
		else
			i -= j;
		i++;
	}
	return (NULL);
}
