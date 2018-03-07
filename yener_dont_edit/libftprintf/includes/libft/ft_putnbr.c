/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:39:37 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/09 21:55:24 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int number)
{
	if (number == -2147483648)
		ft_putstr("-2147483648");
	else if (number < 0)
	{
		ft_putchar('-');
		ft_putnbr(number * -1);
		return ;
	}
	else if (0 <= number && number <= 9)
	{
		ft_putchar((char)('0' + number));
		return ;
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
		return ;
	}
}
