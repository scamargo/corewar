/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_op_codes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:33:20 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 13:44:55 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	get_op_code_asm_corewar(char *op_string)
{
	int		index;
	char	*ops[16] = {"live", "ld", "st", "add", "sub", "and", "or", "xor", "zjmp",
		"ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"};

	index = 0;
	while (index < 16)
	{
		if (ft_strequ(ops[index], op_string))
			return (index + 1);
		index++;
	}
	return (0);
}

static void	update_op_code_single_asm_corewar(char **source_code, int index)
{
	char	*op_string;
	char	*itoa_result;

	op_string = ft_struntil2(*source_code + index, ' ');
	itoa_result = ft_itoa(get_op_code_asm_corewar(op_string));
	while (*(*source_code + index) != ' ')
		ft_delete(source_code, *source_code + index);
	ft_addstr(source_code, *source_code + index, itoa_result);
	ft_strdel4(&op_string, &itoa_result, 0, 0);
}

void		update_op_codes_asm_corewar(char **source_code)
{
	int		index;
	char	is_convert;

	index = 0;
	is_convert = 1;
	while (*(*source_code + index))
	{
		if (is_convert == 1)
		{
			update_op_code_single_asm_corewar(source_code, index);
			is_convert = 0;
		}
		if (*(*source_code + index) == '\n')
			is_convert = 1;
		index++;
	}
}
