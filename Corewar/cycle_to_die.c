/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:48:43 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 18:41:09 by tyang            ###   ########.fr       */
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

int		end_game_mechanics(t_list *process_node, t_cycle *c_vars)
{
	if (c_vars->cycle > 0 && process_node != NULL)
	{
		if ((c_vars->cycle + c_vars->decrease_count * CYCLE_DELTA)
			% c_vars->cycles_to_die == 0)
		{
			purge(process_node);
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
