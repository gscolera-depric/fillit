/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:11:32 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 17:26:03 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	size_t	i;
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		tmp = ft_strnew(len);
		if (tmp)
		{
			i = -1;
			while (s[++i])
				tmp[i] = f(s[i]);
			tmp[i] = '\0';
			return (tmp);
		}
	}
	return (NULL);
}
