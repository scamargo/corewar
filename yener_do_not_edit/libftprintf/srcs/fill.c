/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:39:55 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/30 14:00:29 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_flags(t_format *percent_handler, const char *format)
{
	char	*flags;

	flags = ft_strnew(0);
	if (*format == '%')
		format++;
	while (is_flag(*format))
	{
		ft_strpchar(&flags, *format);
		format++;
	}
	percent_handler->flags = flags;
}

void	fill_width(t_format *percent_handler, const char *format)
{
	if (*format == '%')
		format++;
	while (is_flag(*format))
		format++;
	percent_handler->width = ft_atoi(format);
}

void	fill_precision(t_format *percent_handler, const char *format)
{
	if (*format == '%')
		format++;
	while (is_flag(*format))
		format++;
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		percent_handler->precision = ft_atoi(format + 1);
	else
		percent_handler->precision = -1;
}

void	fill_arguments(t_format *percent_handler, const char *format)
{
	char	*arguments;

	arguments = ft_strnew(0);
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
		ft_strpchar(&arguments, *format);
		if (*format == 'h' && *(format + 1) == 'h')
			ft_strpchar(&arguments, *format);
		else if (*format == 'l' && *(format + 1) == 'l')
			ft_strpchar(&arguments, *format);
	}
	percent_handler->arguments = arguments;
}

void	fill_conversion(t_format *percent_handler, const char *format)
{
	format = (const char*)skip_until_conversion(format);
	if (is_conversion(*format))
		percent_handler->conversion = *format;
	else
		percent_handler->conversion = 0;
}
