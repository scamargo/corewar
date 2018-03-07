# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytuz <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:01:35 by ytuz              #+#    #+#              #
#    Updated: 2018/03/06 14:09:21 by ytuz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -L ../libftprintf -lftprintf/

all:
	gcc -Wall -Wextra -Werror -L ../libftprintf -lftprintf  *.c -o corewar

test:
	read fn && gcc -Wall -Wextra -Werror -L ../libftprintf -lftprintf  $$fn -o corewar

clean:
	rm -rf *.o

fclean: clean
	rm -rf asm

re: fclean all

git:
	git add .
	read msg && git commit -m "$$msg"
	git push

