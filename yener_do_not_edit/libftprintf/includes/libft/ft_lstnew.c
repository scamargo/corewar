/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:35:51 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 15:08:07 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_list == 0)
		return (0);
	if (content == 0)
	{
		new_list->content = 0;
		new_list->content_size = 0;
		return (new_list);
	}
	new_list->content =
		ft_memcpy(ft_memalloc(content_size), content,
				content_size);
	if (new_list->content == 0)
		return (0);
	new_list->content_size = content_size;
	new_list->next = 0;
	return (new_list);
}
