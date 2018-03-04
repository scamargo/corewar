/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_t_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:20:58 by ytuz              #+#    #+#             */
/*   Updated: 2018/02/25 18:20:20 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_type_ftprintf(t_format *info)
{
	if (info->conversion == 0)
		return (0);
	if (info->conversion == '%')
		return (1);
	if (is_char(info))
		return (2);
	if (is_signed_number(info))
		return (3);
	if (is_unsigned_number(info))
		return (4);
	if (is_char_p(info))
		return (5);
	if (is_wint_t(info))
		return (6);
	if (is_wchar_t_p(info))
		return (7);
	return (0);
}

char	*convert_t_format(t_format *info, const char *format,
		va_list ap)
{
	int	type;

	type = get_type_ftprintf(info);
	if (type == 0)
		return (convert_as_is(format));
	if (type == 1)
		return (convert_percent(info));
	if (type == 2)
		return (convert_char(info, ap));
	if (type == 3)
		return (convert_signed_number(info, ap));
	if (type == 4)
		return (convert_unsigned_number(info, ap));
	if (type == 5)
		return (convert_char_p(info, ap));
	if (type == 6)
		return (convert_wint_t(info, ap));
	if (type == 7)
		return (convert_wchar_t_p(info, ap));
	return (0);
}

void	add_minus_to_beginning(char **to_change)
{
	char	*new;

	new = ft_strdup("-");
	ft_strpstr(&new, *to_change);
	ft_strdel(to_change);
	*to_change = new;
}

void	apply_precision(char **to_apply, t_format *info)
{
	char	*new;
	int		digit_count;

	if (**to_apply == '0' && (info->precision == 0))
	{
		ft_strdel(to_apply);
		*to_apply = ft_strnew(0);
		return ;
	}
	digit_count = ft_strlen(*to_apply);
	if (**to_apply == '-')
		digit_count--;
	if (digit_count >= info->precision)
		return ;
	new = ft_strnew(info->precision - digit_count);
	new = ft_memset(new, '0', info->precision - digit_count);
	if (**to_apply == '-')
		add_minus_to_beginning(&new);
	if (**to_apply == '-')
		ft_strpstr(&new, (*to_apply + 1));
	else
		ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}
