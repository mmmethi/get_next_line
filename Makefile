# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmmethi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 14:51:05 by mmmethi           #+#    #+#              #
#    Updated: 2019/07/05 14:51:21 by mmmethi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	 make -C libft/ fclean
	 make -C libft/
	 clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	 clang -Wall -Wextra -Werror -I libft/includes -o maintest.o -c maintest.c
	 clang -o test_gnl maintest.o get_next_line.o -I libft/includes -L libft/ -lft 

clean:
	make -C libft/ clean
	rm -rf get_next_line.o maintest.o

fclean: clean
	make -C libft/ fclean
	rm -rf test_gnl

re: fclean all

