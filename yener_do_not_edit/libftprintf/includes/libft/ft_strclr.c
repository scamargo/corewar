/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:25:20 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/08 21:54:03 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *string)
{
	size_t	string_length;

	if (string == 0)
		return ;
	string_length = ft_strlen(string);
	while (string_length > 0)
	{
		string[string_length - 1] = (char)0;
		string_length--;
	}
}
