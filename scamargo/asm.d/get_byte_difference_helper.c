/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte_difference_helper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:48:20 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 19:26:48 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	get_byte_difference_helper_asm_corewar(int small, int large,
		char *source_code)
{
	int	byte_difference;

	byte_difference = 0;
	large -= small;
	while (small > 0)
	{
		source_code = ft_strchr(source_code, '\n') + 1;
		small--;
	}
	while (*source_code && large > 0)
	{
		if (*source_code == ' ')
			byte_difference++;
		if (*source_code == '\n')
			large--;
		source_code++;
	}
	return (byte_difference);
}
