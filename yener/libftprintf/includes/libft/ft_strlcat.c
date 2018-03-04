/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:29:49 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:39:16 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	index;

	index = 0;
	dest_len = ft_strlen((const char*)dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	while (dest_len + index < size)
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[size - 1] = '\0';
	return (dest_len + src_len);
}
