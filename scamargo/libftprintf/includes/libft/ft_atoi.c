/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:57:30 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/09 21:58:11 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_iswhitespace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n' ||
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *string)
{
	int	sign;
	int	number;

	while (atoi_iswhitespace(*string) == 1)
		string++;
	number = 0;
	sign = 1;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign *= -1;
		string++;
	}
	while (ft_isdigit(*string) == 1)
	{
		number *= 10;
		number += sign * (int)(*string - '0');
		string++;
	}
	return (number);
}
