/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:43:52 by rfork             #+#    #+#             */
/*   Updated: 2019/10/28 16:39:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_save(char **line, char **s_buf)
{
	size_t	len;
	char	*temp;

	len = ft_strchr(*s_buf, '\n') ? ft_strlen(ft_strchr(*s_buf, '\n')) : 0;
	len = ft_strlen(*s_buf) - len;
	if (!(*line = ft_strsub(*s_buf, 0, len)))
		return (-1);
	if (ft_strchr(*s_buf, '\n'))
	{
		if (!(temp = ft_strdup(ft_strchr(*s_buf, '\n') + 1)))
			return (-1);
		ft_strdel(s_buf);
		*s_buf = temp;
	}
	else
		ft_strdel(s_buf);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*s_buf[OPEN_MAX];
	int			ret;
	char		*temp;

	if (fd < 0 || fd > 10240 || !line || ((read(fd, buf, 0)) < 0))
		return (-1);
	if (!s_buf[fd])
		if (!(s_buf[fd] = ft_strnew(0)))
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(temp = ft_strjoin(s_buf[fd], buf)))
			return (-1);
		free(s_buf[fd]);
		s_buf[fd] = temp;
		if ((ft_strchr(s_buf[fd], '\n')))
			return (ft_save(line, &s_buf[fd]));
	}
	if (s_buf[fd])
		if (s_buf[fd][0])
			return (ft_save(line, &s_buf[fd]));
	return (0);
}
