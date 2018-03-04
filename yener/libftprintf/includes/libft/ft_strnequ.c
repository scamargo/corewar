/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:23:06 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 14:48:16 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *string1, char const *string2, size_t size)
{
	if (string1 == 0 || string2 == 0)
		return (0);
	while (*string1 && *string2 && size > 0)
	{
		if (*string1 != *string2)
			return (0);
		string1++;
		string2++;
		size--;
	}
	return (1);
}
