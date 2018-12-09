/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:37:43 by gscolera          #+#    #+#             */
/*   Updated: 2018/11/28 21:55:35 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_next_word(const char *str, char c)
{
	int l;
	int i;

	l = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

static int	ft_words_count(const char *str, char c)
{
	int i;
	int stat;
	int w;

	i = -1;
	stat = 0;
	w = 0;
	while (str[++i])
	{
		if (str[i] != c && stat == 0)
		{
			stat = 1;
			w++;
		}
		if (str[i] == c)
			stat = 0;
	}
	return (w);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	int		i;
	int		words;

	if (!s || !(tmp = (char **)malloc(sizeof(*tmp) *
	(ft_words_count(s, c) + 1))))
		return (NULL);
	i = 0;
	words = ft_words_count(s, c);
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		if (!(tmp[i++] = ft_strsub(s, 0, ft_next_word(s, c))))
		{
			ft_free_array(tmp);
			return (NULL);
		}
		s += ft_next_word(s, c);
	}
	tmp[i] = 0;
	return (tmp);
}
