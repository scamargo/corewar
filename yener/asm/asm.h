/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:37:07 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 13:57:13 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"
# include "../libftprintf/includes/ft_printf.h"

void	asm_corewar(char *file_path);

t_as	*get_bytes_asm_corewar(char *file_string);

t_as	*create_byte_asm_corewar(char byte);

void	free_asm_corewar(t_as *bytes);

void	put_bytes_asm_corewar(t_as *bytes, int fd);

#endif
