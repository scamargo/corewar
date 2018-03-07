/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:02:07 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 20:32:04 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	index;
	char	*dest_char;
	char	*src_char;

	index = 0;
	dest_char = (char *)dest;
	src_char = (char *)src;
	while (index < size)
	{
		dest_char[index] = src_char[index];
		index++;
	}
	return (dest);
}
