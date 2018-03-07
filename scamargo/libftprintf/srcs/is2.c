/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:53:01 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 18:54:05 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_hash_to_p(char **to_apply)
{
	char	*new;

	new = ft_strdup("0x");
	ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}

void	modify_hash(char **to_apply)
{
	char	character;

	if (ft_strchr(*to_apply, 'x') == 0 && ft_strchr(*to_apply, 'X') == 0)
		return ;
	if (ft_strchr(*to_apply, 'x'))
		character = 'x';
	else
		character = 'X';
	*(ft_strchr(*to_apply, character)) = '0';
	*(ft_strchr(*to_apply, '0') + 1) = character;
}

void	apply_others(char **to_apply, t_format *info)
{
	if (info->precision != -1 && ft_strchr("cCsS", info->conversion) == 0)
		apply_precision(to_apply, info);
	if (info->precision != -1 && ft_strchr("sS", info->conversion))
		apply_precision_s(to_apply, info);
	if (info->conversion == 'p')
		apply_hash_to_p(to_apply);
	apply_flags(to_apply, info);
	apply_width(to_apply, info);
	if (ft_strchr("xX", info->conversion) && ft_strchr(info->flags, '#'))
		modify_hash(to_apply);
}

int		is_wchar_t_p(t_format *info)
{
	if (info->conversion != 's' && info->conversion != 'S')
		return (0);
	if (info->conversion == 's' && ft_strequ(info->arguments, "l")
		== 0)
		return (0);
	return (1);
}

char	*convert_wchar_t_p(t_format *info, va_list ap)
{
	char	*result;
	wchar_t	*pointer;

	pointer = va_arg(ap, wchar_t *);
	result = ft_strnew(0);
	while (*pointer)
	{
		ft_strpchar(&result, (char)(*pointer));
		pointer++;
	}
	apply_others(&result, info);
	return (result);
}
