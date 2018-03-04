/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:41:29 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 14:48:37 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *string, unsigned int start, size_t size)
{
	char			*substring;
	unsigned int	index;

	substring = (char*)malloc(sizeof(char) * (size + 1));
	if (substring == 0 || string == 0)
		return (0);
	index = 0;
	while (index < size)
	{
		substring[index] = string[start + index];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
