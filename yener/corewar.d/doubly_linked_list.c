/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:32:37 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/06 22:19:47 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_doublyadd(t_doubly **alst, t_doubly *new)
{
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}

t_doubly	*ft_doublydelone(t_doubly **curr, t_doubly **head, void (*del)(void *, size_t))
{
	t_doubly	*prev;
	t_doubly	*next;

	prev = (*curr)->prev;
	next = (*curr)->next;
	if (*head == *current)
	{
		*head = next;
		next->prev = NULL;
	}
	else
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
	del(curr->content, curr->content_size);
	free(curr);
	*curr = next;
}

int		ft_doublycount(t_doubly *list)
{
	t_doubly	*temp;
	t_process	*curr;
	int			i;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		curr = temp->content;
		temp = temp->next;
		i++;
	}
	return (i);
}

t_doubly	*ft_doublynew(void const *content, size_t content_size)
{
	t_doubly *node;

	if (!(node = ft_memalloc(sizeof(t_doubly))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (!(node->content = ft_memalloc(content_size)))
		{
			free(node);
			return (NULL);
		}
		ft_memmove(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

