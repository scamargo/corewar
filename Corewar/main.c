/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:20:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 18:36:11 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main()
{
	t_core	*arena;
	int		i;

	i = 0;
	arena = (t_core*)ft_memalloc(sizeof(t_core));
	ft_memset(arena->core, 0,  MEM_SIZE);
	arena->core[MEM_SIZE - 1] = '\0';
	while (i < MEM_SIZE)
	{
		printf("%4d, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", arena->core[i], arena->core[i+1], arena->core[i+2], arena->core[i+3], arena->core[i+4], arena->core[i+5], arena->core[i+6], arena->core[i+7]);
		i += 8;
	}
	//read_file(); implemet	
}
