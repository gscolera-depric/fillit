/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:20:26 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/28 15:27:26 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	if (size == (size_t)(-1))
		return (NULL);
	tmp = (char*)malloc(size + 1);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
