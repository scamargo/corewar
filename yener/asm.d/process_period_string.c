/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_period_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 19:57:32 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 20:02:41 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	char	*get_new_period_short_asm_corewar(char *period_string)
{


void			process_period_string_asm_corewar(char **period_string)
{
	char	*new_period;

	if (*(*period_string + 2) == '.')
		new_period = get_new_period_short_asm_corewar(*period_string);
	else
		new_period = get_new_period_int_asm_corewar(*period_string);
	ft_strdel(period_string);
	*period_string = new_period;
}
