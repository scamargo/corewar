/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_magic_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:54:39 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 13:57:32 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*start_magic_number_asm_corewar(void)
{
	char			*magic_number;
	unsigned int	*u_int_t;
	char			*char_t;

	magic_number = ft_strnew(0);
	u_int_t = (unsigned int *)malloc(sizeof(unsigned int) * 1);
	*u_int_t = COREWAR_EXEC_MAGIC;
	char_t = (char*)u_int_t;
	append_byte_asm_corewar(&magic_number, char_t[3]);
	append_byte_asm_corewar(&magic_number, char_t[2]);
	append_byte_asm_corewar(&magic_number, char_t[1]);
	append_byte_asm_corewar(&magic_number, char_t[0]);
	ft_strpchar(&magic_number, '\n');
	free(u_int_t);
	return (magic_number);
}
