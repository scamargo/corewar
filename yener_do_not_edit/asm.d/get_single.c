/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:06:04 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 22:12:09 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_single_indirect_asm_corewar(char *single_arg, char is_trunc)
{
	char	*bytes;

	bytes = ft_strnew(0);
	if (is_trunc == 0)
		ft_strpstr(&bytes, ". ");
	ft_strpstr(&bytes, single_arg);
	ft_strpchar(&bytes, ' ');
	return (bytes);
}

char	*get_single_direct_asm_corewar(char *single_arg, char is_trunc)
{
	char	*bytes;

	bytes = ft_strnew(0);
	if (is_trunc)
		ft_strpstr(&bytes, ". ");
	else
		ft_strpstr(&bytes, ". . . ");
	ft_strpstr(&bytes, single_arg);
	ft_strpchar(&bytes, ' ');
	return (bytes);
}
