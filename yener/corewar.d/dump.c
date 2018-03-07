/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:18:27 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 23:47:26 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		dump_champ_corewar(t_ch *champ)
{
	ft_printf("BYTE DUMP FOR CHAMP NAME %s\n", champ->name);
	dump_bytes_corewar(champ->content, champ->size);
	ft_putendl("END OF BYTES");
}

static void	dump_processes_corewar(t_cw *hash)
{
	unsigned int	process_count;
	t_pc			*last;

	process_count = 0;
	if (hash->process_head == 0)
	{
		ft_putendl("NO PROCESSES TO DISPLAY");
		return ;
	}
	process_count = 0;
	last = hash->process_head;
	ft_putendl("START OF PROCESS DUMP");
	while (last)
	{
		ft_printf("PROCESS %3u OF PC %5u OF BYTE DECIMAL %3hhd\n", process_count, last->process_counter, hash->core[last->process_counter]);
		process_count++;
		last = last->next;
	}
	ft_putendl("END OF PROCESS DUMP");
}

void		dump_bytes_corewar(char *bytes, unsigned int size)
{
	unsigned int	index;
	char			byte_count;

	index = 0;
	while (index < size)
	{
		ft_printf("%4d", *(bytes + index));
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

void		dump_decimal_corewar(t_cw *hash)
{
	unsigned int	index;
	char			byte_count;

	byte_count = 0;
	index = 0;
	ft_putendl("CORE BYTES");
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
	ft_putendl("END OF BYTES");
	dump_processes_corewar(hash);
}
