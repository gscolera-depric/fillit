/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixequ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:57:34 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/29 13:06:28 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrixequ(char **str, char **str1)
{
	if (!str || !str1)
		return (0);
	while (*str && *str1)
	{
		if (ft_strequ(*str, *str1) == 0)
			return (0);
		str++;
		str1++;
	}
	return (1);
}
