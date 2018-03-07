/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:30:00 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 18:45:35 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_hash(char **to_apply, t_format *info)
{
	char	*new;

	if (**to_apply == '0' || (ft_strlen(*to_apply) == 0 &&
		ft_strchr("xX", info->conversion)))
		return ;
	new = ft_strdup("0");
	if (info->conversion == 'x')
		ft_strpchar(&new, 'x');
	else if (info->conversion == 'X')
		ft_strpchar(&new, 'X');
	ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}

void	apply_plus(char **to_apply)
{
	char	*new;

	if (**to_apply == '-')
		return ;
	new = ft_strdup("+");
	ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}

void	apply_space(char **to_apply)
{
	char	*new;

	if (**to_apply == '-')
		return ;
	new = ft_strdup(" ");
	ft_strpstr(&new, *to_apply);
	ft_strdel(to_apply);
	*to_apply = new;
}

void	apply_flags(char **to_apply, t_format *info)
{
	if (info->conversion == 'p')
		return ;
	if ((ft_strchr("oxX", info->conversion) && ft_strchr(info->flags, '#')))
		apply_hash(to_apply, info);
	if (ft_strchr("dDi", info->conversion) && ft_strchr(info->flags, '+'))
		apply_plus(to_apply);
	else if (ft_strchr("dDi", info->conversion) && ft_strchr(info->flags, ' '))
		apply_space(to_apply);
}

void	apply_width(char **to_apply, t_format *info)
{
	if ((int)ft_strlen(*to_apply) >= info->width)
		return ;
	if (ft_strchr(info->flags, '-') != 0)
		apply_negative_width(to_apply, info);
	else
		apply_positive_width(to_apply, info);
}
