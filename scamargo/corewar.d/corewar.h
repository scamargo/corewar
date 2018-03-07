/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:32:35 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/07 13:19:53 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/includes/ft_printf.h"
# include "op.h"

typedef struct		s_pc
{
	char			said_live;
	char			registry[REG_NUMBER];
	unsigned int	process_counter;
	unsigned char	cycles_to_wait;
	struct s_pc		*next; //TODO: remove
}					t_pc;

typedef struct		s_ch
{
	unsigned char	number;
	char			*name;
	char			*comment;
	unsigned int	size;
	char			*content;
	struct s_ch		*next;
}					t_ch;	

typedef struct		s_cw
{
	char			core[MEM_SIZE];
	unsigned int	cycle_count;
	t_list			*process_head;
	struct s_ch		*champ_head;
}					t_cw;

char				check_args_corewar(int ac, char **av);

void				corewar(char **av);

void				load_champs_corewar(char **av, t_cw *hash);

void				dump_decimal_corewar(t_cw *hash);
 
void				free_corewar(t_cw *hash);

unsigned int		get_champ_size_corewar(int fd);

void				introduce_corewar(t_ch *champ);

void				add_champ_into_hash_corewar(t_ch *champ, t_cw *hash);

void				hexdump_bytes_corewar(char *bytes, unsigned int size);

void				hexdump_core_corewar(t_cw *hash);

void				ft_lst_delnode(t_list *curr_node, t_list **head, t_list **last_node, void (*del)(void *, size_t));

int					ft_lst_count(t_list *node);

void				check_processes_corewar(t_list *head);

#endif
