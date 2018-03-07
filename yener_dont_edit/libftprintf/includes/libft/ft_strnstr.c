/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:14:33 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:51:28 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (index1 < len && *big)
	{
		if (*big == *little)
		{
			index2 = 0;
			while (big[index2] == little[index2] && little[index2]
				&& index1 + index2 < len)
				index2++;
			if (little[index2] == '\0')
				return ((char*)big);
		}
		index1++;
		big++;
	}
	return (0);
}
