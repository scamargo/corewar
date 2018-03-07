/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:27:20 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:11:57 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	index;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			index = 0;
			while (big[index] && little[index] && big[index] == little[index])
				index++;
			if (little[index] == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
