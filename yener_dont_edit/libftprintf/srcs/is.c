/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:45:59 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 13:00:54 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_char(t_format *info)
{
	if (info->conversion != 'c')
		return (0);
	if (ft_strlen(info->arguments) != 0)
		return (0);
	return (1);
}

int	is_unsigned_number(t_format *info)
{
	if (ft_strchr("UuoOxXp", info->conversion) != 0)
		return (1);
	return (0);
}

int	is_signed_number(t_format *info)
{
	if (ft_strchr("dDi", info->conversion) == 0)
		return (0);
	return (1);
}

int	is_char_p(t_format *info)
{
	if (info->conversion != 's')
		return (0);
	if (ft_strlen(info->arguments) != 0)
		return (0);
	return (1);
}

int	is_wint_t(t_format *info)
{
	if (info->conversion != 'c' && info->conversion != 'C')
		return (0);
	if (info->conversion == 'c' && ft_strequ(info->arguments, "l") == 0)
		return (0);
	return (1);
}
