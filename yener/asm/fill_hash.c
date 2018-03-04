/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:59:52 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 15:10:53 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_hash_asm_corewar(t_as *hash)
{
	hash->new_path = get_new_path_asm_corewar(hash->old_path);
	hash->file_string = read_file(hash->old_path);
	//ft_putendl(hash->file_string);
}
