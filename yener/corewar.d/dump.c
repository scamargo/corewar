/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:18:27 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 19:23:13 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_decimal_corewar(t_cw *hash, unsigned int max)
{
	unsigned int	index;
	char			byte_count;

	byte_count = 0;
	index = 0;
	while (index < max)
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
