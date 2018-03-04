/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:19:57 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/09 20:08:54 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (size + 1));
	if (string == 0)
		return (0);
	while (size >= 1)
	{
		string[size] = 0;
		size--;
	}
	string[size] = 0;
	return (string);
}
