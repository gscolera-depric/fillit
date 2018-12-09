/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:42:59 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 17:28:54 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*tmp;
	unsigned int	i;
	size_t			len;

	if (s)
	{
		len = ft_strlen(s);
		tmp = ft_strnew(len);
		if (tmp)
		{
			i = -1;
			while (s[++i])
				tmp[i] = f(i, s[i]);
			tmp[i] = '\0';
			return (tmp);
		}
	}
	return (NULL);
}
