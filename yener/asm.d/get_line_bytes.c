/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:07:30 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 19:17:58 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	check_if_acb_asm_corewar(char *op)
{
	if (ft_strequ(op, "live") || ft_strequ(op, "zjmp")
		|| ft_strequ(op, "fork") || ft_strequ(op, "lfork"))
		return (0);
	return (1);
}

static char	check_if_truncated_asm_corewar(char *op)
{
	if (ft_strequ(op, "zjmp") || ft_strequ(op, "ldi") || ft_strequ(op, "sti")
		|| ft_strequ(op, "fork") || ft_strequ(op, "lldi") ||
		ft_strequ(op, "lfork"))
		return (1);
	return (0);
}

static char	get_single_line_byte_count_asm_corewar(char *line)
{
	char	byte_count;
	char	*op;
	char	*args;
	char	is_acb;
	char	is_truncated;

	byte_count = 1;
	op = ft_struntil2(line, '\t');
	is_acb = check_if_acb_asm_corewar(op);
	byte_count += is_acb;
	is_truncated = check_if_truncated_asm_corewar(op);
	args = ft_strdup(ft_strchr(line, '\t') + 1);
	byte_count += get_arg_byte_count_asm_corewar(args, is_truncated);
	ft_strdel4(&op, &args, 0, 0);
	return (byte_count);
}

static char	*get_single_bytes_asm_corewar(int line_count, char *line)
{
	char	*single_line_bytes;
	char	*to_add;

	single_line_bytes = ft_strnew(0);
	to_add = ft_itoa(line_count);
	ft_strpstr(&single_line_bytes, to_add);
	ft_strpchar(&single_line_bytes, ':');
	ft_strdel(&to_add);
	to_add = ft_itoa(get_single_line_byte_count_asm_corewar(line));
	ft_strpstr(&single_line_bytes, to_add);
	ft_strdel(&to_add);
	return (single_line_bytes);
}	

char		*get_line_bytes_asm_corewar(char *source_code)
{
	char	**dp;
	char	*line_bytes;
	char	*single_line_bytes;
	int		line_count;

	dp  = ft_strsplit(source_code, '\n');
	line_count = 0;
	line_bytes = ft_strnew(0);
	while (*(dp + line_count))
	{
		single_line_bytes = get_single_bytes_asm_corewar(line_count, *(dp + line_count));
		ft_strpstr(&line_bytes, single_line_bytes);
		ft_strpchar(&line_bytes, ' ');
		line_count++;
		ft_strdel(&single_line_bytes);
	}
	free_cdp(dp);
	return (line_bytes);
}
