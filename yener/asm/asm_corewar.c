/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_corewar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:45:18 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 14:26:11 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	check_file_path_asm_corewar(char *file_path)
{
	char	return_status;

	return_status = 1;
	if (ft_strrchr(file_path, '.') == 0)
		return_status = 0;
	file_path = ft_strrchr(file_path, '.') + 1;
	if (return_status == 1 && ft_strequ(file_path, "s") == 0)
		return_status = 0;
	if (return_status == 0)
	{
		ft_error(file_string);
		ft_error(": Not a .s file\n");
		return (0);
	}
	return (1);
}

void	asm_corewar(char *file_path)
{
	char	*file_string;
	char	*new_path;
	char	*preprocessed_string;

	if (check_file_path_asm_corewar(file_path) == 0)
		return ;
	new_path = get_new_path_asm_corewar(file_path);
}
