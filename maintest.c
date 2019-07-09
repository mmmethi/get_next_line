/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmmethi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:52:13 by mmmethi           #+#    #+#             */
/*   Updated: 2019/07/08 11:38:35 by mmmethi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *str;

	fd = open("input", O_RDONLY);
	get_next_line(fd, &str);
	printf("%s\n", str);
	free(str);
	get_next_line(fd, &str);
	printf("%s\n", str);
	return (0);
}
