/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_r_and_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:17:38 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 14:31:03 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	delete_r_and_percent_asm_corewar(char **source_code)
{
	int	index;

	index = 0;
	while (*(*source_code + index))
	{
		if (*(*source_code + index) == 'r' || *(*source_code + index) == '%')
			ft_delete(source_code, *source_code + index);
		index++;
	}
}
