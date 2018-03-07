/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_preprocessed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:24:37 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 00:26:38 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_arg_asm_corewar(char *line)
{
	char	*arg;

	while (*line == ' ' || *line == '\t')
		line++;
	while (*line && *line != ' ' && *line != '\t')
		line++;
	arg = ft_strnew(0);
	while (*line == ' ' || *line == '\t')
		line++;
	while (*line && *line != ' ' && *line != '\t')
	{
		ft_strpchar(&arg, *line);
		line++;
	}
	return (arg);
}

static char	*get_op_asm_corewar(char *line)
{
	char	*op;

	while (*line == ' ' || *line == '\t')
		line++;
	op = ft_strnew(0);
	while (*line && *line != ' ' && *line != '\t')
	{
		ft_strpchar(&op, *line);
		line++;
	}
	return (op);
}

static char	*get_new_line_asm_corewar(char *line)
{
	char	*new_line;
	char	*op;
	char	*arg;
	char	is_acb;
	char	is_trunc;

	op = get_op_asm_corewar(line);
	arg = get_arg_asm_corewar(line);
	is_acb = check_if_acb_asm_corewar(op);
	is_trunc = check_if_trunc_asm_corewar(op);
	new_line = get_new_line_helper_asm_corewar(op, arg, is_acb, is_trunc);
	ft_strdel4(&op, &arg, 0, 0);
	return (new_line);
}

void		get_preprocessed_asm_corewar(char **source_code)
{
	char	*new_code;
	char	*new_line;
	char	**dp;
	char	**dp_head;

	dp = ft_strsplit(*source_code, '\n');
	dp_head = dp;
	while (*dp)
	{
		new_line = get_new_line_asm_corewar(*dp);
		free(*dp);
		*dp = new_line;
		dp++;
	}
	new_code = join_cdp(dp_head, '\n');
	free_cdp(dp_head);
	ft_strpchar(&new_code, '\n');
	ft_strdel(source_code);
	*source_code = new_code;
}
