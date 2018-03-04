/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:10:58 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 18:44:57 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_t_format(t_format *percent_handler, const char *format)
{
	if (*format != '%')
		return ;
	fill_flags(percent_handler, format);
	fill_width(percent_handler, format);
	fill_precision(percent_handler, format);
	fill_arguments(percent_handler, format);
	fill_conversion(percent_handler, format);
	percent_handler->is_special = 0;
}

char	*handle_format(const char *format, va_list ap, int *is_special)
{
	t_format	*info;
	char		*result;

	info = (t_format*)malloc(sizeof(t_format) * 1);
	fill_t_format(info, format);
	result = convert_t_format(info, format, ap);
	if (info->is_special == 1)
		*is_special = 1;
	delete_t_format(&info);
	return (result);
}

void	special_putstr(char *to_print, int is_special)
{
	if (is_special == 0)
		ft_putstr(to_print);
	else
	{
		while (*to_print)
		{
			if (*to_print != 'x')
				ft_putchar(*to_print);
			else
				ft_putchar(0);
			to_print++;
		}
	}
}

char	*handle_non_percent(const char *format, int *bytes_printed)
{
	ft_putchar(*format);
	*bytes_printed += 1;
	return ((char*)format + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes_printed;
	char	*result;
	int		is_special;

	va_start(ap, format);
	bytes_printed = 0;
	is_special = 0;
	while (*format)
	{
		if (*format != '%')
			format = (const char *)handle_non_percent(format, &bytes_printed);
		else
		{
			is_special = 0;
			result = handle_format(format, ap, &is_special);
			special_putstr(result, is_special);
			bytes_printed += ft_strlen(result);
			format = (const char *)skip_until_end(format);
			ft_strdel(&result);
		}
	}
	va_end(ap);
	return (bytes_printed);
}
