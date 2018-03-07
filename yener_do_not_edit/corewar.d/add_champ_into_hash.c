/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champ_into_hash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 19:03:38 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 19:06:00 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_champ_into_hash_corewar(t_ch *champ, t_cw *hash)
{
	t_ch	*last;

	if (hash->champ_head == 0)
	{
		hash->champ_head = champ;
		champ->number = 1;
	}
	else
	{
		last = hash->champ_head;
		while (last->next)
			last = last->next;
		last->next = champ;
		champ->number = last->number + 1;
	}
}
