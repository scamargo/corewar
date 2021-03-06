/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:18:23 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 20:24:11 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	free_pc_corewar(t_pc *head)
{
	if (head->next)
		free_pc_corewar(head->next);
	free(head);
}

static void	free_ch_corewar(t_ch *head)
{
	if (head->next)
		free_ch_corewar(head->next);
	if (head->name)
		free(head->name);
	if (head->comment)
		free(head->comment);
	if (head->content)
		free(head->content);
	free(head);
}

void		free_corewar(t_cw *hash)
{
	if (hash == 0)
		return ;
	if (hash->champ_head)
		free_ch_corewar(hash->champ_head);
	if (hash->process_head)
		free_pc_corewar(hash->process_head);
	free(hash);
}
