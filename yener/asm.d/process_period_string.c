/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_period_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:57:32 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 22:41:40 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	append_new_period_asm_corewar(char **new_period, char to_append)
{
	char	*itoa_result;

	itoa_result = ft_itoa(to_append);
	ft_strpstr(new_period, itoa_result);
	ft_strpchar(new_period, ' ');
	ft_strdel(&itoa_result);
}

static char	*get_new_period_int_asm_corewar(char *period_string)
{
	int		*int_t;
	char	*char_t;
	char	*new_period;

	int_t = (int*)malloc(sizeof(int) * 1);
	*int_t = ft_atoi(period_string + 6);
	char_t = (char*)int_t;
	new_period = ft_strnew(0);
	append_new_period_asm_corewar(&new_period, char_t[3]);
	append_new_period_asm_corewar(&new_period, char_t[2]);
	append_new_period_asm_corewar(&new_period, char_t[1]);
	append_new_period_asm_corewar(&new_period, char_t[0]);
	free(int_t);
	return (new_period);
}

static char	*get_new_period_short_asm_corewar(char *period_string)
{
	short	*short_t;
	char	*char_t;
	char	*new_period;

	short_t = (short*)malloc(sizeof(short) * 1);
	*short_t = ft_atoi(period_string + 2);
	char_t = (char*)short_t;
	new_period = ft_strnew(0);
	append_new_period_asm_corewar(&new_period, char_t[1]);
	append_new_period_asm_corewar(&new_period, char_t[0]);
	free(short_t);
	return (new_period);
}

void		process_period_string_asm_corewar(char **period_string)
{
	char	*new_period;

	if (*(*period_string + 2) == '.')
		new_period = get_new_period_int_asm_corewar(*period_string);
	else
		new_period = get_new_period_short_asm_corewar(*period_string);
	ft_strdel(period_string);
	*period_string = new_period;
}
