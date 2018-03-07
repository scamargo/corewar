/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:34:08 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 21:47:13 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	check_argument_count_corewar(char **av)
{
	unsigned char	arg_count;

	av++;
	arg_count = 0;
	if (ft_strequ(*av, "-dump"))
		av += 2;
	while (*av)
	{
		if (ft_strequ(*av, "-n"))
			av += 2;
		else
			arg_count++;
	}
	if (arg_count == 0 || arg_count > MAX_PLAYERS)
	{
		ft_error("Invalid number of players\n");
		return (0);
	}
	return (1);
}
