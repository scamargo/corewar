/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:50:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 18:50:39 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

void	delete_process(void *process, size_t size)
{
	// TODO: free registry array
	free(process->registries);
	free(process);
}

bool	purge(t_doubly *process_node)
{
	t_process *current_process;

	while (process_node)
	{
		current_process = (t_process*)process_node->content; 
		if (current_process->alive)
			current_process->alive = 0;
		else
			ft_doublydelone(&process_node, delete_process);
		process_node = process_node->next;
	}
}

