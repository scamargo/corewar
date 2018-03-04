/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:39:37 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 14:47:48 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *string1, char const *string2)
{
	if (string1 == 0 || string2 == 0)
		return (0);
	if (ft_strlen(string1) != ft_strlen(string2))
		return (0);
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (0);
		string1++;
		string2++;
	}
	return (1);
}
