/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:37:07 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 17:54:33 by ytuz             ###   ########.fr       */
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
	char		*labels;
	char		*line_bytes;
}				t_as;

void	asm_corewar(char *file_path);

char	*get_new_path_asm_corewar(char *file_path);

void	free_hash_asm_corewar(t_as *to_free);

void	dump_hash_asm_corewar(t_as *to_dump);

t_as	*start_hash_asm_corewar(void);

void	fill_hash_asm_corewar(t_as *hash);

char	*get_labels_asm_corewar(char *source_code);

void	get_encoded_asm_corewar(char **source_code);

char	*get_line_bytes_asm_corewar(char *source_code);

char	get_arg_byte_count_asm_corewar(char *args, char is_truncated);

typedef char* t_op[8];

#endif
