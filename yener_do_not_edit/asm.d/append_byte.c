/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 21:02:22 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 21:03:20 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	append_byte_asm_corewar(char **to_append, char byte)
{
	char	*itoa_result;

	itoa_result = ft_itoa(byte);
	ft_strpstr(to_append, itoa_result);
	ft_strpchar(to_append, ' ');
	ft_strdel(&itoa_result);
}
