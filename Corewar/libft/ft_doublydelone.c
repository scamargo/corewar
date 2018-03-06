/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublydelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:34:18 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/06 11:55:57 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_doubly	*ft_doublydelone(t_doubly *curr, t_doubly **head, void (*del)(void *, size_t))
{
	t_doubly	*prev;
	t_doubly	*next;

	prev = curr->prev;
	next = curr->next;
	del(curr->content, curr->content_size);
	free(curr);
	if (prev != NULL)
	{
		ft_putendl("before");
		prev->next = next;
		ft_putendl("after");
	}
	else
	{
		ft_putendl("before head");
		*head = next;
		next->prev = NULL;
		ft_putendl("after head");
	}
	if (next != NULL)
		next->prev = prev;
	return (next);
}
