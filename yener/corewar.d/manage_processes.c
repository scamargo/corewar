/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:01:20 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/06 22:20:19 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_process(void *content, size_t content_size)
{
	content_size = 0; // TODO: why is content size needed
	free(content);
	content = NULL;
}

void	check_processes_corewar(t_cw *hash)
{
  t_doubly	*process_node;
  t_doubly	*head;
  t_pc		*process;

  head = hash->process_head;
  process_node = head;
  while (process_node)
  {
	process = (t_pc*)process_node->content;
  	if (process->said_live == 0)
    	ft_doublydelone(&process_node, &head, delete_process); 
	else
  		process_node  = process_node->next;
  }
}
