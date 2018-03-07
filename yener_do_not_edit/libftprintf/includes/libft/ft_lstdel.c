/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:54:17 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 12:52:54 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*freer;

	if (alst == 0 || *alst == 0 || del == 0)
		return ;
	while (*alst)
	{
		freer = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&freer, del);
	}
}
