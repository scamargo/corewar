/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:52:46 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 20:27:41 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_champ_content_corewar(int fd, t_ch *champ)
{
	char			*content;
	unsigned int	index;
	char			buffer[CHAMP_MAX_SIZE + 1];

	content = (char*)malloc(sizeof(char) * champ->size);
	index = 0;
	lseek(fd, 16 + PROG_NAME_LENGTH + COMMENT_LENGTH, SEEK_SET);
	read(fd, &buffer, CHAMP_MAX_SIZE);
	ft_memcpy((void*)content, (void*)buffer, champ->size);
	champ->content = content;
}
