/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:57:01 by tyang             #+#    #+#             */
/*   Updated: 2018/03/06 11:58:44 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../vm.h"

int		ft_doublycount(t_doubly *list)
{
	t_doubly	*temp;
	t_process	*curr;
	int			i;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		curr = temp->content;
		ft_putendl("print alive");
		printf("%p alive = %i\n", temp, curr->alive);
		temp = temp->next;
		i++;
	}
	return (i);
}
