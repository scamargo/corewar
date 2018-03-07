/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:13:24 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 19:37:37 by ytuz             ###   ########.fr       */
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
	char			buffer[COMMENT_LENGTH + 1];

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
	champ->content = 0;
	close(fd);
	return (champ);
}

static void	add_next_champ_corewar(char **av, t_cw *hash)
{
	t_ch			*champ;
	t_ch			*last;
	unsigned int	champ_number;

	champ_number = 0;
	if (ft_strequ(*av, "-n"))
	{
		champ = get_champ_from_file_corewar(*(av + 2));
		champ_number = ft_atoi(*(av + 1));
	}
	else
		champ = get_champ_from_file_corewar(*av);
	last = hash->champ_head;
	add_champ_into_hash_corewar(champ, hash);
	if (champ_number != 0)
		champ->number = champ_number;
	introduce_corewar(champ);
}

void		load_champs_corewar(char **av, t_cw *hash)
{
	ft_putendl("Introducing contestants...");
	av++;
	if (ft_strequ(*av, "-dump"))
		av += 2;
	while (*av)
	{
		add_next_champ_corewar(av, hash);
		if (ft_strequ(*av, "-n"))
			av += 2;
		av++;
	}
	//load_the_core_corewar(hash);
}
