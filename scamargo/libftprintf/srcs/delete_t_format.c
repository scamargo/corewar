/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_t_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:25:03 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/31 18:46:43 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delete_t_format(t_format **to_delete)
{
	ft_strdel(&((*to_delete)->flags));
	ft_strdel(&((*to_delete)->arguments));
	ft_memdel((void**)to_delete);
}

void	cast_number(intmax_t *number, t_format *info)
{
	if (info->conversion == 'D')
		*number = (long int)*number;
	else if (ft_strlen(info->arguments) == 0)
		*number = (int)*number;
	else if (ft_strequ(info->arguments, "hh") == 1)
		*number = (char)*number;
	else if (ft_strequ(info->arguments, "h") == 1)
		*number = (short int)*number;
	else if (ft_strequ(info->arguments, "l") == 1)
		*number = (long int)*number;
	else if (ft_strequ(info->arguments, "ll") == 1)
		*number = (long long int)*number;
}

void	cast_unsigned(uintmax_t *number, t_format *info)
{
	if (info->conversion == 'U' || info->conversion == 'p')
		*number = (unsigned long int)*number;
	else if (ft_strlen(info->arguments) == 0)
		*number = (unsigned int)*number;
	else if (ft_strequ(info->arguments, "hh") == 1)
		*number = (unsigned char)*number;
	else if (ft_strequ(info->arguments, "h") == 1)
		*number = (unsigned short int)*number;
	else if (ft_strequ(info->arguments, "l"))
		*number = (unsigned long int)*number;
	else if (ft_strequ(info->arguments, "ll") == 1)
		*number = (unsigned long long int)*number;
}
