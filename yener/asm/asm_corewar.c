/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:45:18 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/03 23:22:54 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	asm_corewar(char *file_path)
{
	char	*file_string;
	char	*assembled_string;
	char	*new_path;
	int		fd;

	file_string = read_file(file_path);
	new_path = get_new_path_asm_corewar(file_path);
	fd = open(new_path, O_CREAT | O_RDWR);
	assembled_string = get_assembled_string_asm_corewar(file_string);
	ft_putstr_fd(assembled_string, fd);
	close(fd);
	ft_strdel4(&file_string, &assembled_string, &new_path, 0);
}
