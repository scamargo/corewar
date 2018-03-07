/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:22:03 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 14:29:29 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_new_path_asm_corewar(char *file_path)
{
	char	*new_path;
	char	*last_period;

	last_period = ft_strrchr(file_path, '.');
	new_path = ft_struntil(file_path, last_period);
	ft_strpstr(&new_path, ".cor");
	return (new_path);
}
