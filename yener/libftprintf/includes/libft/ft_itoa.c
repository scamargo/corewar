/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:08:01 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 18:57:25 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_join(char **string1, char **string2)
{
	char	*string3;

	string3 = ft_strjoin(*string1, *string2);
	ft_strdel(string1);
	ft_strdel(string2);
	*string1 = string3;
	return ;
}

char		*ft_itoa(int number)
{
	char	*string;
	char	*to_delete;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	string = ft_strnew(0);
	if (0 <= number && number <= 9)
	{
		ft_strpchar(&string, number + '0');
		return (string);
	}
	if (number < 0)
	{
		to_delete = ft_itoa(number * -1);
		ft_itoa_join(&string, &to_delete);
		return (string);
	}
	to_delete = ft_itoa(number / 10);
	ft_itoa_join(&string, &to_delete);
	to_delete = ft_itoa(number % 10);
	ft_itoa_join(&string, &to_delete);
	return (string);
}
