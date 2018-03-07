/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:14:10 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 17:52:04 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_precision_s(char **to_change, t_format *info)
{
	char	*new;

	if ((int)ft_strlen(*to_change) <= info->precision)
		return ;
	new = ft_strncpy(ft_strnew(info->precision), *to_change, info->precision);
	ft_strdel(to_change);
	*to_change = new;
}

char	*convert_as_is(const char *format)
{
	char	*end;

	end = skip_until_end(format);
	return (ft_struntil((char*)format, end));
}
