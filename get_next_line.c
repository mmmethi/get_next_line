/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmmethi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:56:05 by mmmethi           #+#    #+#             */
/*   Updated: 2019/07/09 15:03:07 by mmmethi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_open_fd(char *str, int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*store;
	int		ret;

	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		store = str;
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(store);
	}
	if (ret == -1)
		return (NULL);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*mem[MAX];
	char			*s;
	int				val;

	val = 0;
	if (fd < 0 || fd > MAX || line == NULL ||
			BUFF_SIZE < 0 || BUFF_SIZE > MAX_BUFF)
		return (-1);
	if (mem[fd] == NULL || mem[fd][0] == '\0')
	{
		if ((mem[fd] = ft_open_fd(mem[fd], fd)) == NULL)
			return (-1);
	}
	if (mem[fd][0] == '\0')
		return (0);
	while (mem[fd][val] != '\0' && mem[fd][val] != '\n')
		val++;
	*line = ft_strsub(mem[fd], 0, val);
	s = mem[fd];
	if ((mem[fd] = ft_strchr(mem[fd], '\n')) == NULL)
		return (1);
	if (mem[fd][0] != '\0')
		mem[fd] = ft_strsub(mem[fd], 1, ft_strlen(mem[fd]));
	free(s);
	return (1);
}
