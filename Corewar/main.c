/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:20:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/06 16:05:51 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void	dump_core(char *core)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < MEM_SIZE)
	{
		k = 0;
		while (k < 48)
		{
			if (core[i] < 16)
				ft_printf("0%x ", core[i]);
			else
				ft_printf("%x ", core[i]);
			i++;
			k++;
		}
		ft_printf("\n");
	}
}

int		main()
{
	t_core		*arena;
	t_doubly	*head;
	t_cycle		*c_vars;
	int			i;

	i = 0;
	c_vars = init_cycle();
	arena = (t_core*)ft_memalloc(sizeof(t_core));
	ft_memset(arena->core, 0,  MEM_SIZE);
	arena->core[MEM_SIZE - 1] = '\0';
	dump_core(arena->core);
	head = create_processes();
	ft_printf("%i\n", ft_doublycount(head));
	while (end_game_mechanics(head, c_vars))
	{
		c_vars->cycle++;
	}
	ft_putendl("here");
	printf("%i\n", ft_doublycount(head));
	/*while (i < MEM_SIZE)
	{
		printf("%4d, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", arena->core[i], arena->core[i+1], arena->core[i+2], arena->core[i+3], arena->core[i+4], arena->core[i+5], arena->core[i+6], arena->core[i+7]);
		i += 8;
	}*/
	//read_file(); implemet	
}
