/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:22:58 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:55:05 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *string, char (*f)(char))
{
	char	*new;
	size_t	index;
	size_t	size;

	if (string == 0)
		return (0);
	size = ft_strlen(string);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == 0 || size == 0)
		return (0);
	index = 0;
	while (index < size)
	{
		new[index] = f(string[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}
