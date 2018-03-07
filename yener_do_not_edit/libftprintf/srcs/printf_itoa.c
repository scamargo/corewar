/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:17:56 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/30 21:41:36 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_itoa_join(char **string1, char **string2)
{
	char	*string3;

	string3 = ft_strjoin(*string1, *string2);
	ft_strdel(string1);
	ft_strdel(string2);
	*string1 = string3;
}

char		*printf_itoa_negative(intmax_t number, char conversion)
{
	char	*result;
	char	*to_add;

	result = ft_strdup("-");
	number *= -1;
	to_add = printf_itoa(number, conversion);
	ft_strpstr(&result, to_add);
	ft_strdel(&to_add);
	return (result);
}

char		*printf_itoa_hexa(uintmax_t number, char capital)
{
	char	*result;
	char	*to_add;
	char	character;

	result = ft_strnew(0);
	if (number > 15)
	{
		to_add = printf_itoa_hexa(number / 16, capital);
		printf_itoa_join(&result, &to_add);
		to_add = printf_itoa_hexa(number % 16, capital);
		printf_itoa_join(&result, &to_add);
		return (result);
	}
	if (number < 10)
		character = '0' + number;
	else if (capital == 1)
		character = 'A' + number - 10;
	else
		character = 'a' + number - 10;
	ft_strpchar(&result, character);
	return (result);
}

char		*printf_itoa_base(uintmax_t number, int base)
{
	char	*result;
	char	*to_add;

	result = ft_strnew(0);
	if (number < (unsigned long long)base)
	{
		ft_strpchar(&result, number + '0');
		return (result);
	}
	to_add = printf_itoa_base(number / base, base);
	printf_itoa_join(&result, &to_add);
	to_add = printf_itoa_base(number % base, base);
	printf_itoa_join(&result, &to_add);
	return (result);
}

char		*printf_itoa(uintmax_t number, char conversion)
{
	if (conversion == 'd' || conversion == 'i'
		|| conversion == 'u' || conversion == 'D' || conversion == 'U')
		return (printf_itoa_base(number, 10));
	if (conversion == 'o' || conversion == 'O')
		return (printf_itoa_base(number, 8));
	if (conversion == 'x' || conversion == 'p')
		return (printf_itoa_hexa(number, 0));
	if (conversion == 'X')
		return (printf_itoa_hexa(number, 1));
	return (0);
}
