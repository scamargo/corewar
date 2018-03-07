/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:35:53 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 20:28:59 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *data, int c, size_t len)
{
	unsigned char	*string;

	if (len == 0)
		return (data);
	string = (unsigned char *)data;
	while (len > 0)
	{
		*string = (unsigned char)c;
		string++;
		len--;
	}
	return (data);
}
