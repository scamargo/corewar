/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:46:55 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:38:31 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *string1, const char *string2)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (string1[index1] != '\0')
		index1++;
	index2 = 0;
	while (string2[index2])
	{
		string1[index1] = string2[index2];
		index1++;
		index2++;
	}
	string1[index1] = (char)0;
	return (string1);
}
