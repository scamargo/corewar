/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:50:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 15:59:38 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

bool	purge(t_list *process_node)
{
	t_list *curr_node;

	while (*process_node)
	{
		curr_node = process_node->content;
		if (curr_node->alive == 1)
			curr_node->alive = 0;
		else
			ft_removeone(curr_node);
	}
}

void	live_op(t_list *process_node, int cycle)
{
	
