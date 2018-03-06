/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublydelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:34:18 by scamargo          #+#    #+#             */
/*   Updated: 2018/03/05 15:35:12 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_doublydelone(t_doubly **alst, void (*del)(void *, size_t))
{
	t_doubly	*prev;
	t_doubly	*next;

	prev = (*alst)->prev;
	next = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	prev->next = next;
	next->prev = prev;
}
