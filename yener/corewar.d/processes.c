/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:31:46 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 23:01:27 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_pc	

t_pc	*start_process(unsigned int process_counter)
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
