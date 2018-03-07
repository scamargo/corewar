/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:34:08 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 19:38:07 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int ac, char **av)
{
	if (check_args_corewar(ac, av) == 0)
		return (0);
	corewar(av);
	while (1)
		;
	return (0);
}