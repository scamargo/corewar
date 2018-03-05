/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:20:17 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 11:59:48 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	cham1(int champ_nb, )
{
	live(champ_nb);
	

char	*create_arena()
{
	char *arena;

	if ((arena = ft_memalloc(sizeof(MEM_SIZE))) == NULL)
	{
		ft_putendl_fd(2, "Error--failed to allocate memory for arena");
		exit();
	}
	return (arena);
}

int		main()
{
	create_arena();
	//read_file(); implemet

}

