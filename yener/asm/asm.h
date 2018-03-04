/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:37:07 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 15:02:09 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"
# include "../libftprintf/includes/ft_printf.h"

typedef struct	s_as
{
	char		*old_path;
	char		*new_path;
	char		*file_string;
	char		*name;
	char		*comment;
	char		*source_code;
}				t_as;

void	asm_corewar(char *file_path);

char	*get_new_path_asm_corewar(char *file_path);

void	free_hash_asm_corewar(t_as *to_free);

void	dump_hash_asm_corewar(t_as *to_dump);

t_as	*start_hash_asm_corewar(void);

void	fill_hash_asm_corewar(t_as *hash);

#endif
