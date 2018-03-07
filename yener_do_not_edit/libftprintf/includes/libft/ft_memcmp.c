/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:36:06 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:22:34 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *data1, const void *data2, size_t size)
{
	unsigned char	*string1;
	unsigned char	*string2;

	if (data1 == 0 && data2 == 0)
		return (0);
	string1 = (unsigned char*)data1;
	string2 = (unsigned char*)data2;
	while (size > 0)
	{
		if (*string1 != *string2)
			return ((int)(*string1 - *string2));
		string1++;
		string2++;
		size--;
	}
	string1--;
	string2--;
	return ((int)(*string1 - *string2));
}
