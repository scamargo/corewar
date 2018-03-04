/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:33:47 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/30 14:00:27 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_flag(char character)
{
	if (character == '#' || character == '0' || character == '-'
		|| character == '+' || character == ' ')
		return (1);
	return (0);
}

char	is_argument(char character)
{
	if (character == 'h' || character == 'l' || character == 'j'
		|| character == 'z')
		return (1);
	return (0);
}

char	is_conversion(char character)
{
	if (ft_strchr("sSpdDioOuUxXcC%", character) != 0)
		return (1);
	return (0);
}

char	*skip_until_conversion(const char *format)
{
	if (*format == '%')
		format++;
	while (is_flag(*format))
		format++;
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		format++;
	while (ft_isdigit(*format))
		format++;
	if (is_argument(*format))
	{
		if (*format == 'h' && *(format + 1) == 'h')
			format++;
		else if (*format == 'l' && *(format + 1) == 'l')
			format++;
		format++;
	}
	return ((char *)format);
}

char	*skip_until_end(const char *format)
{
	format = (const char *)skip_until_conversion(format);
	if (is_conversion(*format))
		format++;
	return ((char *)format);
}
