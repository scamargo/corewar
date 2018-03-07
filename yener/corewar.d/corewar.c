/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:14:40 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 19:24:09 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_dump_cycles_corewar(char **av)
{
	av++;
	if (ft_strequ(*av, "-dump"))
		return (ft_atoi(*(av + 1)));
	else
		return (-1);
}

static t_cw	*start_hash_corewar(void)
{
	t_cw			*hash;
	unsigned int	index;

	hash = (t_cw*)malloc(sizeof(t_cw) * 1);
	index = 0;
	while (index < MEM_SIZE)
	{
		hash->core[index] = 0;
		index++;
	}
	hash->process_head = 0;
	hash->champ_head = 0;
	return (hash);
}

void		corewar(char **av)
{
	t_cw	*hash;
	int		dump_cycles_number;

	dump_cycles_number = get_dump_cycles_corewar(av);
	hash = start_hash_corewar();
	load_champs_corewar(av, hash);
	dump_decimal_corewar(hash, MEM_SIZE);
	//fight_corewar(hash, dump_cycles_number);
	free_corewar(hash);
}
