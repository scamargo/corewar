/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:02:19 by ytuz              #+#    #+#             */
/*   Updated: 2018/02/24 19:06:07 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addchar(char **head, char *location, char to_add)
{
	char	*first_half;
	char	*second_half;

	first_half = ft_struntil(*head, location);
	ft_strpchar(&first_half, to_add);
	second_half = ft_strdup(location);
	ft_strpstr(&first_half, second_half);
	free(second_half);
	ft_strdel(head);
	*head = first_half;
}
