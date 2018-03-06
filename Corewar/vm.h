/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:06:46 by tyang             #+#    #+#             */
/*   Updated: 2018/03/06 11:52:51 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "op.h"

typedef struct s_core
{
	char		core[MEM_SIZE];
}				t_core;

typedef struct s_args
{
	int			dir_v;
}				t_args;

typedef struct s_process
{
	int			pc;
	char		registries[REG_NUMBER];
	int			alive;
}				t_process;

typedef struct s_cycle
{
	int			cycle;
	int			live_calls;
	int			cycles_to_die;
	int			decrease_count;
}				t_cycle;

void			delete_process(void *process, size_t size);
void			purge(t_doubly **head);
t_cycle			*init_cycle();
t_doubly		*create_processes();
int				end_game_mechanics(t_doubly *process_node, t_cycle *c_vars);
