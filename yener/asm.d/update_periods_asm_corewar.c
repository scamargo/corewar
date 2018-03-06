/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_periods_asm_corewar.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:38:04 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 19:50:52 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_period_string_asm_corewar(char *source_code, 

static void	update_next_period_asm_corewar(char **source_code)
{
	int		start_index;
	int		end_index;
	char	*period_string;

	start_index = ft_strchr(*source_code, '.') - *source_code;
	end_index = start_index;
	while (*(*source_code + end_index) == '.')
		end_index += 2;
	end_index++;
	period_string = get_period_string_asm_corewar(*source_code, start_index, end_index);
	process_period_string_asm_corewar(&period_string);
	delete_current_period_asm_corewar(source_code, start_index, end_index);
	ft_addstr(source_code, *source_code + start_index, period_string);
	ft_strdel(&period_string);
}

void		update_periods_asm_corewar(char **source_code)
{
	while (ft_strchr(*source_code, '.'))
		update_next_period_asm_corewar(source_code);
}
