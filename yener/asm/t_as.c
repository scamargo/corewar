/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_as.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:43:53 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 15:10:18 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	try_to_free_asm_corewar(char *to_free)
{
	if (to_free)
		free(to_free);
}

t_as	*start_hash_asm_corewar(void)
{
	t_as	*new;

	new = (t_as*)malloc(sizeof(t_as) * 1);
	new->old_path = 0;
	new->new_path = 0;
	new->file_string = 0;
	new->name = 0;
	new->comment = 0;
	new->source_code = 0;
	return (new);
}

void	dump_hash_asm_corewar(t_as *to_dump)
{
	if (to_dump->old_path)
		ft_printf("Old path: %s\n", to_dump->old_path);
	if (to_dump->new_path)
		ft_printf("New path: %s\n", to_dump->new_path);
	if (to_dump->name)
		ft_printf("Name: %s\n", to_dump->name);
	if (to_dump->comment)
		ft_printf("Comment: %s\n", to_dump->comment);
	if (to_dump->source_code)
		ft_printf("Source code:\n%s\n", to_dump->source_code);
}

void	free_hash_asm_corewar(t_as *to_free)
{
	try_to_free_asm_corewar(to_free->old_path);
	try_to_free_asm_corewar(to_free->new_path);
	//try_to_free_asm_corewar(to_free->file_string);
	try_to_free_asm_corewar(to_free->name);
	try_to_free_asm_corewar(to_free->comment);
	try_to_free_asm_corewar(to_free->source_code);
	free(to_free);
}
