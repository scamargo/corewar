# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytuz <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:01:35 by ytuz              #+#    #+#              #
#    Updated: 2018/03/03 23:18:04 by ytuz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -L ../libftprintf -lftprintf/

all:
	gcc -Wall -Wextra -Werror -L ../libftprintf -lftprintf  *.c -o asm

test:
	read fn && gcc -Wall -Wextra -Werror -L ../libftprintf -lftprintf  $$fn -o asm

clean:
	rm -rf *.o

fclean: clean
	rm -rf asm

re: fclean all

git:
	git add .
	read msg && git commit -m "$$msg"
	git push

