/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:48:43 by tyang             #+#    #+#             */
/*   Updated: 2018/03/06 11:58:42 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_cycle		*init_cycle()
{
	t_cycle		*new;

	new = (t_cycle*)ft_memalloc(sizeof(t_cycle));
	new->cycle = 0;
	new->live_calls = 0;
	new->cycles_to_die = CYCLE_TO_DIE;
	new->decrease_count = 0;
	return (new);
}

int		end_game_mechanics(t_doubly *process_node, t_cycle *c_vars)
{
	if (c_vars->cycle >= 0)
		purge(&process_node);
	if (c_vars->cycle > 0 && process_node != NULL)
	{
		if ((c_vars->cycle + c_vars->decrease_count * CYCLE_DELTA)
			% c_vars->cycles_to_die == 0)
		{
			//purge(process_node);
			c_vars->live_calls++;
			if (c_vars->live_calls == 21 && process_node != NULL)
			{
				if (c_vars->cycles_to_die < 0)
					c_vars->cycles_to_die = 0;
				c_vars->decrease_count++;
				c_vars->live_calls = 0;
				c_vars->cycles_to_die -= CYCLE_DELTA;
			}
		}
		return (1);
	}
	return (0);
}

t_doubly	*create_processes()
{
	int		i;
	t_doubly	*head;
	t_doubly	*new;
	t_process	process;

	process.alive = 1;
	//process.registries = 0;
	process.pc = 0;
	i = 1;
	head = ft_doublynew(&process, sizeof(t_process));
	while (i < 20)
	{
		if (i % 2 == 0)
			process.alive = 1;
		else
			process.alive = 0;
		new = ft_doublynew(&process, sizeof(t_process));
		ft_doublyadd(&head, new);
		i++;
	}
	return (head);
}
