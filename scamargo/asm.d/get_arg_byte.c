/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:39:26 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 17:47:15 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	get_single_arg_bytes_asm_corewar(char arg, char is_truncated)
{
	if (arg == 'r')
		return (1);
	else if (arg == '%')
	{
		if (is_truncated)
			return (2);
		else
			return (4);
	}
	if (is_truncated)
		return (1);
	return (2);
}

char		get_arg_byte_count_asm_corewar(char *args, char is_truncated)
{
	char	bytes;
	char	**dp;
	char	**dp_head;

	bytes = 0;
	dp = ft_strsplit(args, SEPARATOR_CHAR);
	dp_head = dp;
	while (*dp)
	{
		bytes += get_single_arg_bytes_asm_corewar(**dp, is_truncated);
		dp++;
	}
	free_cdp(dp_head);
	return (bytes);
}
