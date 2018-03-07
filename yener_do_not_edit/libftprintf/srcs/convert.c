/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:02:33 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 17:44:13 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_char(t_format *info, va_list ap)
{
	char	*result;
	char	to_add;

	result = ft_strnew(0);
	to_add = (char)va_arg(ap, int);
	if (to_add != 0)
		ft_strpchar(&result, to_add);
	else
	{
		ft_strpstr(&result, "x");
		info->is_special = 1;
	}
	apply_others(&result, info);
	return (result);
}

char	*convert_signed_number(t_format *info, va_list ap)
{
	char		*result;
	intmax_t	number;

	number = va_arg(ap, intmax_t);
	cast_number(&number, info);
	if (number < 0)
		result = printf_itoa_negative(number, info->conversion);
	else
		result = printf_itoa(number, info->conversion);
	apply_others(&result, info);
	return (result);
}

char	*convert_unsigned_number(t_format *info, va_list ap)
{
	char		*result;
	uintmax_t	number;

	number = va_arg(ap, uintmax_t);
	cast_unsigned(&number, info);
	result = printf_itoa(number, info->conversion);
	apply_others(&result, info);
	return (result);
}

char	*convert_char_p(t_format *info, va_list ap)
{
	char	*result;
	char	*string;

	string = va_arg(ap, char *);
	if (string == 0)
		result = ft_strdup("(null)");
	else
		result = ft_strdup(string);
	apply_others(&result, info);
	return (result);
}

char	*convert_wint_t(t_format *info, va_list ap)
{
	char	*result;
	char	character;

	result = ft_strnew(0);
	character = (char)va_arg(ap, intmax_t);
	if (character == 0)
	{
		ft_strpchar(&result, 'x');
		info->is_special = 1;
	}
	else
		ft_strpchar(&result, character);
	apply_others(&result, info);
	return (result);
}
