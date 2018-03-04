/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:54:44 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 20:31:02 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *data, size_t size)
{
	size_t	index;
	char	*c;

	index = 0;
	c = data;
	while (index < size)
	{
		c[index] = 0;
		index++;
	}
}
