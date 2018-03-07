/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:37:56 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:11:36 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (src[index] && index < len)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dest[index] = (char)0;
		index++;
	}
	return (dest);
}
