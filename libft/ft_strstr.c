/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:58:41 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 15:35:07 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] && haystack[i] == needle[j])
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
