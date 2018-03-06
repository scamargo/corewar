/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:06:46 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 18:42:20 by tyang            ###   ########.fr       */
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
	void		*registries;
	int			alive;
}				t_process;

typedef struct s_cycle
{
	int			cycle;
	int			live_calls;
	int			cycles_to_die;
	int			decrease_count;
}				t_cycle;
