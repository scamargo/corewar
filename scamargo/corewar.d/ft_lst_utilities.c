/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:32:37 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/07 13:22:48 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_lst_delnode(t_list *current, t_list **p_head, t_list **p_last, void (*del)(void *, size_t))
{
	t_list	*next;

	next = current->next;
	if (*p_head == current)
	{
		ft_printf("deleting head node\n");
		*p_head = next;
	}
	else
	{
		ft_printf("deleting non-head node\n");
		(*p_last)->next = next;
	}
	del((current)->content, current->content_size);
	free(current);
	current = NULL;
}

int		ft_lst_count(t_list *node)
{
	int			i;

	i = 0;
	while (node)
	{
		ft_printf("(%p: %i)->", node, ((t_pc*)node->content)->said_live);
		node = node->next;
		i++;
	}
	ft_printf("%p\n\n", node);
	return (i);
}
