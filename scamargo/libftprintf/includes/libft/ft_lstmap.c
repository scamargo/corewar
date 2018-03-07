/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:06:05 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 15:08:25 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_to_end(t_list **head, t_list *tail)
{
	t_list	*last_elem;

	if (head == 0 || tail == 0)
		return ;
	if (*head == 0)
	{
		*head = tail;
		return ;
	}
	last_elem = *head;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = tail;
	return ;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*output;

	output = 0;
	while (lst)
	{
		add_to_end(&output, f(lst));
		lst = lst->next;
	}
	return (output);
}
