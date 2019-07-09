/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmmethi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:35:05 by mmmethi           #+#    #+#             */
/*   Updated: 2019/07/09 12:49:43 by mmmethi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 75

# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(const int fd, char **line);
#endif
