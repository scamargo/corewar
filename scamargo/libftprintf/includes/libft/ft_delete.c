/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:06:57 by ytuz              #+#    #+#             */
/*   Updated: 2018/02/24 19:07:05 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete(char **head, char *to_del)
{
	char	*first_half;
	char	*second_half;

	first_half = ft_struntil(*head, to_del);
	second_half = ft_strdup(to_del + 1);
	ft_strpstr(&first_half, second_half);
	free(second_half);
	ft_strdel(head);
	*head = first_half;
}
