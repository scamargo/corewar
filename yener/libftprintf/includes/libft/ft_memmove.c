/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:33:21 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:06:01 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*dest_char;

	dest_char = (char *)dest;
	if (src > dest)
	{
		while (size >= 1)
		{
			*dest_char = *((char *)src);
			dest_char++;
			src++;
			size--;
		}
	}
	else if (dest >= src)
	{
		while (size >= 1)
		{
			dest_char[size - 1] = *((char *)(src + size - 1));
			size--;
		}
	}
	return (dest);
}
