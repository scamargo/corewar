/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:34:08 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 22:10:55 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int ac, char **av)
{
	if (check_args_corewar(ac, av) == 0)
		return (0);
	corewar(av);
	return (0);
}