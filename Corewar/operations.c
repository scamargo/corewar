/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:50:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/06 15:54:03 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	delete_process(void *process, size_t size)
{
	// TODO: free registry array
	free(process);
	process = NULL;
	size = 0;
}

void	purge(t_doubly **head)
{
	t_process	*current_process;
	t_doubly	*curr_node;

	curr_node = *head;
	while (curr_node)
	{
		current_process = (t_process*)curr_node->content;
		if (current_process->alive)
		{
			current_process->alive = 0;
			curr_node = curr_node->next;
		}
		else
			curr_node = ft_doublydelone(curr_node, head, delete_process);
	}
}

