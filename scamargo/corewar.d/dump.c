/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:18:27 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 20:41:23 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_decimal_corewar(t_cw *hash)
{
	unsigned int	index;
	char			byte_count;

	byte_count = 0;
	index = 0;
	while (index < MEM_SIZE)
	{
		ft_printf("%4d", hash->core[index]);
		byte_count++;
		if (byte_count == 15)
		{
			ft_putchar('\n');
			byte_count = 0;
		}
		index++;
	}
	if (byte_count != 0)
		ft_putchar('\n');
}

void	hexdump_bytes_corewar(char *bytes, unsigned int size)
{
	unsigned int i;
	unsigned int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		k = 0;
		while (k < 16)
		{
			if (bytes[i] < 16)
				ft_printf("0%x ", bytes[i]);
			else
				ft_printf("%x ", bytes[i]);
			i++;
			k++;
		}
		ft_printf("\n");
	}
}

void	hexdump_core_corewar(t_cw *hash)
{
	hexdump_bytes_corewar(hash->core, MEM_SIZE);
}
