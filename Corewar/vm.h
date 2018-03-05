/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:06:46 by tyang             #+#    #+#             */
/*   Updated: 2018/03/05 11:59:47 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <op.h>

typedef struct s_args
{
	int			dir_v;
}				t_args;

typedef struct s_process
{
	int			pc;
	void		*registries;
	bool		alive;
}				t_process;


