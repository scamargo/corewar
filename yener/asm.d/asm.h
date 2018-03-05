/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:37:07 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 23:13:00 by ytuz             ###   ########.fr       */
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
}				t_as;

void	asm_corewar(char *file_path);

char	*get_new_path_asm_corewar(char *file_path);

void	free_hash_asm_corewar(t_as *to_free);

void	dump_hash_asm_corewar(t_as *to_dump);

t_as	*start_hash_asm_corewar(void);

void	fill_hash_asm_corewar(t_as *hash);

char	*get_labels_asm_corewar(char *source_code);

void	get_encoded_asm_corewar(char **source_code);

void	remove_comments_asm_corewar(char **source_code);

char	check_for_comment_asm_corewar(char *line);

char	check_if_acb_asm_corewar(char *op);

char	check_if_trunc_asm_corewar(char *op);

char	*get_single_direct_asm_corewar(char *single_arg, char is_trunc);

char	*get_single_indirect_asm_corewar(char *single_arg, char is_trunc);

void	get_preprocessed_asm_corewar(char **source_code);

char	*get_new_line_helper_asm_corewar(char *op, char *arg, char is_acb,
	char is_trunc);

#endif