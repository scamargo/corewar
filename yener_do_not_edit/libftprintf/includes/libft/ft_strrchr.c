/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:59:35 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 13:14:10 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	size_t	len;

	len = ft_strlen(string);
	if (c == 0)
		return ((char *)(string + len));
	while (len >= 1)
	{
		if (string[len - 1] == c)
			return ((char*)(string + len - 1));
		len--;
	}
	return (0);
}
