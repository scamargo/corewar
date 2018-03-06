/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublynew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:44:48 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/05 19:31:31 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		//node->content = (void*)content;
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
