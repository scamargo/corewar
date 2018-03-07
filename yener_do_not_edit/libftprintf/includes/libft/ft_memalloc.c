/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmaloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:32:27 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/04 19:34:03 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*data;
	char	*string;

	if (size == 0)
		return (0);
	data = (void*)malloc(sizeof(void) * size);
	if (data == 0)
		return (0);
	string = data;
	while (size > 0)
	{
		*string = (char)0;
		string++;
		size--;
	}
	return (data);
}
