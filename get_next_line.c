/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmmethi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:56:05 by mmmethi           #+#    #+#             */
/*   Updated: 2019/07/09 12:41:47 by mmmethi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_readl(int fd, char **str)
{
	char	*buf;
	char	*store;
	int		ret;

	if (!(buf = (char *)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		store = ft_strjoin(*str, buf);
		free(*str);
		*str = store;
	}
	free(buf);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char *mem;
	char		*s;
	int			val;

	if ((!mem && (mem = (char *)malloc(sizeof(*mem))) == NULL)
			|| fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	s = ft_strchr(mem, '\n');
	while (s == NULL)
	{
		val = ft_readl(fd, &mem);
		if (val == 0)
		{
			if (ft_strlen(mem) == 0)
				return (0);
			mem = ft_strjoin(mem, "\n");
		}
		if (val < 0)
			return (-1);
		else
			s = ft_strchr(mem, '\n');
	}
	*line = ft_strsub(mem, 0, ft_strlen(mem) - ft_strlen(s));
	mem = ft_strdup(s + 1);
	return (1);
}
