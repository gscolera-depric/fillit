/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:08:41 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/29 20:27:34 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;

	i = -1;
	if (!(copy = (char*)malloc(ft_strlen(src) + 1)))
		return (0);
	while (src[++i])
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}
