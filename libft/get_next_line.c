/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:01:03 by gscolera          #+#    #+#             */
/*   Updated: 2018/12/07 19:37:47 by gscolera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_takeline(char **data, char **line)
{
	char	*tmp;
	int		i;
	int		l;

	i = -1;
	l = 0;
	tmp = ft_strdup(*data);
	while (tmp[++i] != '\n' && tmp[i])
		l++;
	*line = ft_strnew(l);
	ft_strncpy(*line, *data, l);
	ft_strdel(data);
	if (l < (int)ft_strlen(tmp))
		*data = ft_strdup(&tmp[l + 1]);
	else
		*data = ft_strdup("\0");
	ft_strdel(&tmp);
}

static void		join(char **data, char *buff)
{
	char *tmp;

	tmp = ft_strnew(ft_strlen(*data) + ft_strlen(buff));
	ft_strcpy(tmp, *data);
	ft_strcat(tmp, buff);
	ft_strdel(data);
	*data = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static	t_file	*choose_file(t_file **file, int fd)
{
	t_file	*tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	tmp->fd = fd;
	tmp->ret = 0;
	tmp->data = ft_strnew(0);
	tmp->next = *file;
	*file = tmp;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*this;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	this = choose_file(&file, fd);
	while ((this->ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[this->ret] = '\0';
		join(&this->data, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (this->ret < BUFF_SIZE && ft_strlen(this->data) == 0)
		return (0);
	ft_takeline(&this->data, line);
	return (1);
}
