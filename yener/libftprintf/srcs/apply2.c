/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:09:08 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 17:52:15 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_negative_width(char **to_apply, t_format *info)
{
	char	*new;

	if ((int)ft_strlen(*to_apply) >= info->width)
		return ;
	new = ft_memset(ft_strnew(info->width), ' ', info->width);
	new = ft_memcpy((void*)new, (void*)(*to_apply), ft_strlen(*to_apply));
	ft_strdel(to_apply);
	*to_apply = new;
}

void	apply_positive_width_zero(char **to_apply, t_format *info)
{
	char	*new;
	char	first_character;
	int		length;

	if (info->precision != -1)
	{
		apply_positive_width_space(to_apply, info);
		return ;
	}
	first_character = 0;
	if (**to_apply == ' ' || **to_apply == '+' || **to_apply == '-')
		first_character = **to_apply;
	length = info->width - ft_strlen(*to_apply) + (first_character != 0);
	new = ft_memset(ft_strnew(length), '0', length);
	if (first_character)
	{
		new[0] = first_character;
		ft_strpstr(&new, *to_apply + 1);
	}
	else
		ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}

void	apply_positive_width_space(char **to_apply, t_format *info)
{
	char	*new;
	int		length;

	length = info->width - ft_strlen(*to_apply);
	new = ft_memset(ft_strnew(length), ' ', length);
	ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}

void	apply_positive_width(char **to_apply, t_format *info)
{
	if ((int)ft_strlen(*to_apply) >= info->width)
		return ;
	if (ft_strchr(info->flags, '0'))
		apply_positive_width_zero(to_apply, info);
	else
		apply_positive_width_space(to_apply, info);
}

char	*convert_percent(t_format *info)
{
	char	*result;

	result = ft_strdup("%");
	apply_others(&result, info);
	return (result);
}
