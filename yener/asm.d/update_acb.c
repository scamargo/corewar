/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_acb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:45:03 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 14:15:41 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	add_to_acb_value_asm_corewar(int to_add, int arg_count)
{
	if (arg_count == 0)
		return (to_add / 10 * 128 + to_add % 10 * 64);
	if (arg_count == 1)
		return (to_add / 10 * 32 + to_add % 10 * 16);
	if (arg_count == 2)
		return (to_add / 10 * 8 + to_add % 10 * 4);
	return (to_add / 10  * 2 + to_add % 10);
}

static int	get_acb_value_helper_asm_corewar(char **dp)
{
	char	arg_count;
	int		acb_value;

	acb_value = 0;
	arg_count = 0;
	while (*dp)
	{
		if (**dp != '.')
		{
			if (**dp == 'r')
				acb_value += add_to_acb_value_asm_corewar(1, arg_count);
			else if (**dp == '%')
				acb_value += add_to_acb_value_asm_corewar(10, arg_count);
			else
				acb_value += add_to_acb_value_asm_corewar(11, arg_count);
			arg_count++;
		}
		dp++;
	}
	return (acb_value);
}

static int	get_acb_value_asm_corewar(char *acb_start)
{
	char	*args_till_newline;
	char	**dp;
	int		acb_value;

	acb_start = ft_strchr(acb_start, ' ') + 1;
	args_till_newline = ft_struntil2(acb_start, '\n');
	dp = ft_strsplit(args_till_newline, ' ');
	acb_value = get_acb_value_helper_asm_corewar(dp);
	free_cdp(dp);
	ft_strdel(&args_till_newline);
	return (acb_value);
}

static void	update_single_acb_asm_corewar(char **source_code, int index)
{
	int		acb_value;
	char	*itoa_result;

	acb_value = get_acb_value_asm_corewar(*source_code + index);
	while (*(*source_code + index) != ' ')
		ft_delete(source_code, *source_code + index);
	itoa_result = ft_itoa(acb_value);
	ft_addstr(source_code, *source_code + index, itoa_result);
	ft_strdel(&itoa_result);
}

void		update_acb_asm_corewar(char **source_code)
{
	int	index;

	index = 0;
	while (*(*source_code + index))
	{
		if (*(*source_code + index) == ' ' || *(*source_code + index) == '\n')
			index++;
		else
		{
			if (ft_strnequ(*source_code + index, "ACB", 3))
				update_single_acb_asm_corewar(source_code, index);
			while (*(*source_code + index) != '\n' && *(*source_code + index) != ' ')
				index++;
		}
	}
}
