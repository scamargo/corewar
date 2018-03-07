/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:52:13 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 11:43:53 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *string)
{
	char	*result;
	int		index;

	result = (char*)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (string[index])
	{
		result[index] = string[index];
		index++;
	}
	result[index] = 0;
	return (result);
}
