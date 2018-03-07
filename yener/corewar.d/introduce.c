/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:48:59 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 18:57:18 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	introduce_corewar(t_ch *champ)
{
	ft_printf("* Player %hhu, weighing %u bytes, \"%s\" (\"%s\") !\n", 
		champ->number, champ->size, champ->name, champ->comment);
}
