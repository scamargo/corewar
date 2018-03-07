/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:05:37 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 20:42:53 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned char	*dest_char;
	size_t			index;

	dest_char = (unsigned char *)dest;
	index = 0;
	while (index < size)
	{
		dest_char[index] = *((unsigned char *)src);
		if (*(unsigned char *)src == (unsigned char)c)
			return (dest + index + 1);
		index++;
		src++;
	}
	return (0);
}
