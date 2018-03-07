/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:44:22 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:39:04 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *string1, const char *string2, size_t size)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	while (string1[index1] != 0)
		index1++;
	index2 = 0;
	while (string2[index2] != 0 && index2 < size)
	{
		string1[index1] = string2[index2];
		index1++;
		index2++;
	}
	string1[index1] = 0;
	return (string1);
}
