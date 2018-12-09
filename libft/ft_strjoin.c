/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:30:26 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 16:54:18 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = ft_strnew(len);
	if (!tmp)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		tmp[i] = s1[i];
	while (s2[++j])
		tmp[i++] = s2[j];
	return (tmp);
}
