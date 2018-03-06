/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:32:35 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 14:55:33 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/includes/ft_printf.h"
# include "op.h"

typedef struct		s_cw
{
	char			struct_type;
	char			core[MEM_SIZE];
	struct s_pc		*process_head;
	struct s_ch		*champ_head;
}					t_cw;

typedef struct		s_pc
{
	char			struct_type;
	char			said_live;
	unsigned int	process_counter;
	unsigned char	cycles_to_wait;
	struct s_pc		*next;
}

typedef struct		s_ch
{
	char			struct_type;
	char			*name;
	char			

char	check_args_corewar(int ac, char **av);

void	corewar(char **av);

#endif
