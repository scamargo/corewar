/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:28:28 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:56:07 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *string1, char const *string2)
{
	char	*string;
	size_t	index;

	if (string1 == 0 || string2 == 0)
		return (0);
	string = (char *)malloc(sizeof(char)
							* (ft_strlen(string1) + ft_strlen(string2) + 1));
	if (string == 0)
		return (0);
	index = 0;
	while (*string1)
	{
		string[index] = *string1;
		index++;
		string1++;
	}
	while (*string2)
	{
		string[index] = *string2;
		index++;
		string2++;
	}
	string[index] = '\0';
	return (string);
}
