/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:58:13 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/03 19:29:29 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_array(char **str)
{
	int i;

	if (!*str || !str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
