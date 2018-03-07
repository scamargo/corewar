/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champions_cdp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:46:03 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 21:59:17 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	**start_champions_corewar(void)
{
	char	**champions;
	int		index;

	champions = (char**)malloc(sizeof(char*) * 5);
	index = 0;
	while (index < 5)
	{
		champions[index] = 0;
		index++;
	}
	return (champions);
}

static void	add_to_champions_corewar(char **champions, char *to_add)
{
	while (*champions)
		champions++;
	*champions = ft_strdup(to_add);
}

char		**get_champions_cdp_corewar(char **av)
{
	char	**champions;

	champions = start_champions_corewar();	
	av++;
	if (ft_strequ(*av, "-dump"))
		av += 2;
	while (*av)
	{
		if (ft_strequ(*av, "-n"))
		{
			champions[ft_atoi(*(av + 1))] = ft_strdup(*(av + 2));
			av += 2;
		}
		else
		{
			add_to_champions_corewar(champions, *av);
			av++;
		}
	}
	return (champions);
}
