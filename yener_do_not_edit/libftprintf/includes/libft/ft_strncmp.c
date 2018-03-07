/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:46:45 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:11:05 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *string1, const char *string2, size_t size)
{
	size_t			index;
	unsigned char	*unsigned1;
	unsigned char	*unsigned2;

	unsigned1 = (unsigned char *)string1;
	unsigned2 = (unsigned char *)string2;
	if (size == 0)
		return (0);
	index = 0;
	while (index < size)
	{
		if (unsigned1[index] == 0 || unsigned2[index] == 0)
			return ((int)(unsigned1[index] - unsigned2[index]));
		if (unsigned1[index] != unsigned2[index])
			return ((int)(unsigned1[index] - unsigned2[index]));
		index++;
	}
	index--;
	return ((int)(unsigned1[index] - unsigned2[index]));
}
