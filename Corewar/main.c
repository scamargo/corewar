/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:20:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/06 15:40:35 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

/*void	dump_core(char *core)
{
	char *hex = 
*/

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
	head = create_processes();
	ft_printf("42 in hex: %x\n: ", 42); 
	ft_printf("%p this is the head pointer \n", head);
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
