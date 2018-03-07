/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:42:50 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 19:45:05 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	get_champ_size_corewar(int fd)
{
	unsigned int	size;
	unsigned int	*u_int_t;
	char			*char_t;
	char			buffer[4];

	lseek(fd, 8 + PROG_NAME_LENGTH, SEEK_SET);
	char_t = (char*)malloc(sizeof(char) * 4);
	read(fd, &buffer, 4);
	char_t[0] = buffer[3];
	char_t[1] = buffer[2];
	char_t[2] = buffer[1];
	char_t[3] = buffer[0];
	u_int_t = (unsigned int *)char_t;
	size = *u_int_t;
	free(char_t);
	return (size);
}
