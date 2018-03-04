/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:19:38 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 18:24:49 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *string, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (string == 0 || f == 0)
		return ;
	while (string[index])
	{
		f(index, string + index);
		index++;
	}
}
