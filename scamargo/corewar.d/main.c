/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:34:08 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/07 13:22:33 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*void	delete_process(void *content, size_t content_size)
{
	content_size = 0; // TODO: why is content size needed
	free(content);
	content = NULL;
}*/

t_list	*create_test_processes()
{
	int			i;
	t_list		*head;
	t_list		*new;
	t_pc	*process;

	i = 0;
	while (i < 6)
	{
		process = ft_memalloc(sizeof(t_pc));
		if (i % 2 == 0)
			process->said_live = 1;
		else
			process->said_live = 0;
		if (i == 0)
			head = ft_lstnew(process, sizeof(t_pc));
		else
		{
			new = ft_lstnew(process, sizeof(t_pc));
			ft_lstadd(&head, new);
		}
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	if (check_args_corewar(ac, av) == 0)
		return (0);
	//testing
	t_list *head = create_test_processes();
	//t_list *current = head;
	ft_printf("process count initial: %i\n", ft_lst_count(head));
	check_processes_corewar(head);
	/*t_list *last = NULL;
	ft_lst_delnode(&current, &head, &last, delete_process);
	ft_printf("next count: %i\n", ft_lst_count(head));
	last = current;
	current = current->next;
	ft_printf("next count: %i\n", ft_lst_count(head));
	ft_lst_delnode(&current, &head, &last, delete_process);
	ft_printf("next count: %i\n", ft_lst_count(head));
	last = current;
	current = current->next;
	ft_printf("next count: %i\n", ft_lst_count(head));
	ft_lst_delnode(&current, &head, &last, delete_process);
	last = current;
	current = current->next;
	ft_printf("next count: %i\n", ft_lst_count(head));
	if (current)
		ft_printf(": %p\n", current);*/
	ft_printf("process count final: %i\n", ft_lst_count(head));
	//testing
	corewar(av);
	while (1)
		;
	return (0);
}
