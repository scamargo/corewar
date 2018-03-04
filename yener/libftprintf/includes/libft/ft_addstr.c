/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:03:53 by ytuz              #+#    #+#             */
/*   Updated: 2018/02/24 19:05:52 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addstr(char **head, char *location, char *to_add)
{
	char	*first_half;
	char	*second_half;

	first_half = ft_struntil(*head, location);
	ft_strpstr(&first_half, to_add);
	second_half = ft_strdup(location);
	ft_strpstr(&first_half, second_half);
	ft_strdel(head);
	*head = first_half;
}
