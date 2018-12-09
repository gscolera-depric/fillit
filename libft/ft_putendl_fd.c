/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:40 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/25 16:41:48 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int i;

	i = 0;
	if (!str || fd < 0)
		return ;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
	ft_putchar_fd('\n', fd);
}
