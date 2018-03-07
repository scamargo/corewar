/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:31:46 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 23:38:12 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	add_process_corewar(t_cw *hash, unsigned int process_counter)
{
	t_pc	*last_process;

	if (hash->process_head == 0)
	{
		hash->process_head = start_process_corewar(process_counter);
		return ;
	}
	last_process = hash->process_head;
	while (last_process->next)
		last_process = last_process->next;
	last_process->next = start_process_corewar(process_counter);
	last_process->next->prev = last_process;
}

static char	load_next_process_corewar(t_cw *hash, unsigned int index_diff)
{
	t_ch	*champ;

	if (hash->champ_head == 0 || hash->champ_head->number == 0)
		return (0);
	champ = hash->champ_head;
	while (champ->next && champ->next->number != 0)
		champ = champ->next;
	add_process_corewar(hash, index_diff * (champ->number - 1));
	champ->number = 0;
	return (1);
}

void		load_processes_corewar(t_cw *hash)
{
	unsigned int	index_diff;
	char			max_champ_number;

	max_champ_number = get_max_champ_number_corewar(hash);
	index_diff = MEM_SIZE / max_champ_number;
	while (load_next_process_corewar(hash, index_diff))
		;
}

t_pc		*start_process_corewar(unsigned int process_counter)
{
	t_pc	*process;

	process = (t_pc*)malloc(sizeof(t_pc) * 1);
	process->prev = 0;
	process->next = 0;
	process->said_live = 0;
	process->process_counter = process_counter;
	process->cycles_to_wait = 0;
	return (process);
}
