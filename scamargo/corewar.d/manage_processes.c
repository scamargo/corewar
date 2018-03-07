/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:01:20 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/07 13:19:58 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_process(void *content, size_t content_size)
{
	content_size = 0; // TODO: why is content size needed
	free(content);
	content = NULL;
}

void	check_processes_corewar(t_list *head)
{
  t_list	*process_node;
  t_list	*last_node;
  t_list	*next;
  t_pc		*process;

  process_node = head;
  last_node = NULL;
  while (process_node)
  {
	next = process_node->next;
	process = (t_pc*)process_node->content;
  	if (process->said_live == 0)
    	ft_lst_delnode(process_node, &head, &last_node, delete_process);
	else
		last_node = process_node;
  	process_node  = process_node->next;
	ft_printf("next count: %i\n", ft_lst_count(head));
	ft_printf("current: %p\n", process_node);
  }
}
