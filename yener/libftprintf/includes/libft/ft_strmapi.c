/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:07:53 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:55:25 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*new;

	if (string == 0)
		return (0);
	new = (char*)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (new == 0 || string == 0)
		return (0);
	index = 0;
	while (string[index])
	{
		new[index] = f(index, string[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}
