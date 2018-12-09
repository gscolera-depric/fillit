/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:10:09 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/29 13:03:27 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		*list = tmp;
		tmp = tmp->next;
		free((*list)->content);
		free(*list);
	}
}
