/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:45:18 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 22:43:28 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	create_file_asm_corewar(t_as *hash)
{
	int		fd;
	char	*source;

	fd = open(hash->new_path, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	source = hash->file_string;
	while (*source)
	{
		if (*source == ' ' || *source == '\n')
			source++;
		else
		{
			ft_putchar_fd((char)(ft_atoi(source)), fd);
			while (*source && *source != ' ' && *source != '\n')
				source++;
		}
	}
	close(fd);
}

static char	check_if_exists_asm_corewar(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(file_path);
		ft_error(": Inaccessible file\n");
		return (0);
	}
	close(fd);
	return (1);
}

static char	check_file_path_asm_corewar(char *file_path)
{
	char	return_status;
	char	*pointer;

	return_status = 1;
	if (ft_strrchr(file_path, '.') == 0)
		return_status = 0;
	pointer = ft_strrchr(file_path, '.') + 1;
	if (return_status == 1 && ft_strequ(pointer, "s") == 0)
		return_status = 0;
	if (return_status == 0)
	{
		ft_error(file_path);
		ft_error(": Not a .s file\n");
		return (0);
	}
	return (1);
}

void	asm_corewar(char *file_path)
{
	t_as	*hash;

	hash = start_hash_asm_corewar();
	hash->old_path = ft_strdup(file_path);
	if (check_file_path_asm_corewar(hash->old_path) == 0
		|| check_if_exists_asm_corewar(hash->old_path) == 0)
	{
		free_hash_asm_corewar(hash);
		return ;
	}
	fill_hash_asm_corewar(hash);
	//dump_hash_asm_corewar(hash);
	create_file_asm_corewar(hash);
	free_hash_asm_corewar(hash);
}
