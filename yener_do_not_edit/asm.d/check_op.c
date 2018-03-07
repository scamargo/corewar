/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:43:41 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 00:28:42 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_single_arg_asm_corewar(char *single_arg, char is_trunc)
{
	char	*single_bytes;

	if (*single_arg == 'r')
	{
		single_bytes = ft_strnew(0);
		ft_strpstr(&single_bytes, single_arg);
		ft_strpchar(&single_bytes, ' ');
		return (single_bytes);
	}
	if (*single_arg == '%')
		return (get_single_direct_asm_corewar(single_arg, is_trunc));
	return (get_single_indirect_asm_corewar(single_arg, is_trunc));
}

static char	*get_arg_bytes_asm_corewar(char *arg, char is_trunc)
{
	char	*arg_bytes;
	char	*single_arg;
	char	*single_arg_bytes;

	arg_bytes = ft_strnew(0);
	while (*arg)
	{
		single_arg = ft_struntil2(arg, ',');
		single_arg_bytes  = get_single_arg_asm_corewar(single_arg, is_trunc);
		ft_strpstr(&arg_bytes, single_arg_bytes);
		ft_strdel(&single_arg_bytes);
		ft_strdel(&single_arg);
		while (*arg && *arg != ',')
			arg++;
		if (*arg)
			arg++;
	}
	return (arg_bytes);
}

char		*get_new_line_helper_asm_corewar(char *op, char *arg,
	char is_acb, char is_trunc)
{
	char	*new_line;
	char	*arg_bytes;

	new_line = ft_strnew(0);
	ft_strpstr(&new_line, op);
	ft_strpchar(&new_line, ' ');
	if (is_acb)
		ft_strpstr(&new_line, "ACB ");
	arg_bytes = get_arg_bytes_asm_corewar(arg, is_trunc);
	ft_strpstr(&new_line, arg_bytes);
	ft_strdel(&arg_bytes);
	return (new_line);
}

char		check_if_acb_asm_corewar(char *op)
{
	if (ft_strequ(op, "live") || ft_strequ(op, "zjmp") ||
		ft_strequ(op, "fork") || ft_strequ(op, "lfork"))
		return (0);
	return (1);
}

char		check_if_trunc_asm_corewar(char *op)
{
	if (ft_strequ(op, "zjmp") || ft_strequ(op, "ldi") ||
	ft_strequ(op, "sti") || ft_strequ(op, "fork") ||
	ft_strequ(op, "lldi") || ft_strequ(op, "lfork"))
		return (1);
	return (0);
}
