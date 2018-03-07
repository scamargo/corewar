# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytuz <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:55:53 by ytuz              #+#    #+#              #
#    Updated: 2018/01/31 20:33:30 by ytuz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all:		$(NAME)

$(NAME):
			gcc -Wall -Wextra -Werror -I includes/ -c srcs/*.c
			gcc -Wall -Wextra -Werror -I includes/libft/ -c includes/libft/*.c
			ar rc $(NAME) *.o

clean:
			/bin/rm -rf *.o

fclean:		clean
			/bin/rm -rf $(NAME)

re:			fclean all
