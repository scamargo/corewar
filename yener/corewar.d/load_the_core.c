/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_the_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:29:39 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 23:01:33 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	get_max_champ_number_corewar(t_cw *hash)
{
	t_ch	*champ;

	champ = hash->champ_head;
	while (champ->next)
		champ = champ->next;
	return ((char)(champ->number));
}

static void	load_single_champ_to_core_corewar(t_ch *champ,
	t_cw *hash, unsigned int index_diff)
{
	unsigned int	start;
	unsigned int	index;

	start = (champ->number - 1) * index_diff;
	index = 0;
	while (index < champ->size)
	{
		hash->core[start] = champ->content[index];
		start++;
		index++;
	}
}

void		load_the_core_corewar(t_cw *hash)
{
	t_ch			*champ;
	char			max_champ_number;
	unsigned int	index_diff;

	max_champ_number = get_max_champ_number_corewar(hash);
	index_diff = MEM_SIZE / max_champ_number;
	champ = hash->champ_head;
	while (champ)
	{
		load_single_champ_to_core_corewar(champ, hash, index_diff);
		champ = champ->next;
	}
}
