/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_comments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:58:10 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 20:05:06 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	check_for_comment_asm_corewar(char *line)
{
	while (*line == '\t')
		line++;
	if (*line == '.' || *line == COMMENT_CHAR)
		return (1);
	return (0);
}
