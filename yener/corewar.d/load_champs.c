/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:13:24 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 23:01:01 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	*get_champ_name_corewar(int fd)
{
	char	buffer[PROG_NAME_LENGTH + 1];

	lseek(fd, 4, SEEK_SET);
	read(fd, &buffer, PROG_NAME_LENGTH);
	return (ft_strdup(buffer));
}

static char	*get_champ_comment_corewar(int fd)
{
	char	buffer[COMMENT_LENGTH + 1];

	lseek(fd, 8 + PROG_NAME_LENGTH + 4, SEEK_SET);
	read(fd, &buffer, COMMENT_LENGTH);
	return (ft_strdup(buffer));
}

static t_ch	*get_champ_from_file_corewar(char *path)
{
	t_ch	*champ;
	int		fd;

	champ = (t_ch*)malloc(sizeof(t_ch) * 1);
	fd = open(path, O_RDONLY);
	champ->name = get_champ_name_corewar(fd);
	champ->comment = get_champ_comment_corewar(fd);
	champ->size = get_champ_size_corewar(fd);
	champ->number = 0;
	champ->next = 0;
	get_champ_content_corewar(fd, champ);
	close(fd);
	return (champ);
}

static void	add_next_champ_corewar(char *champion, t_cw *hash)
{
	t_ch			*champ;
	t_ch			*last;

	champ = get_champ_from_file_corewar(champion);
	if (hash->champ_head == 0)
	{
		hash->champ_head = champ;
		champ->number = 1;
	}
	else
	{
		last = hash->champ_head;
		while (last->next)
			last = last->next;
		last->next = champ;
		champ->number = last->number + 1;
	}
	introduce_corewar(champ);
	ft_printf("%s BYTES:\n", champ->name);
	dump_bytes_corewar(champ->content, champ->size);
	ft_putendl("END OF BYTES");
}

void		load_champs_corewar(char **champions, t_cw *hash)
{
	ft_putendl("Introducing contestants...");
	while (*champions)
	{
		add_next_champ_corewar(*champions, hash);
		champions++;
	}
	load_the_core_corewar(hash);
}
