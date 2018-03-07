/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total_byte_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:10:31 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 21:19:47 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	get_total_byte_count_asm_corewar(char *source_code)
{
	unsigned int	byte_count;

	byte_count = 0;
	while (*source_code)
	{
		if (*source_code != ' ' && *source_code != '\n')
		{
			byte_count++;
			while (*source_code != ' ' && *source_code != '\n')
				source_code++;
		}
		else
			source_code++;
	}
	return (byte_count);
}
