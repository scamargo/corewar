/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_comments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:18:17 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 20:07:56 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_processed_line_asm_corewar(char *line)
{
	char	*new;

	new = line;
	while (*new == '\t')
		new++;
	new = ft_struntil2(new, COMMENT_CHAR);
	return (new);
}

void	remove_comments_asm_corewar(char **source_code)
{
	char	**dp;
	char	**dp_head;
	char	*without_comments;
	char	*processed_line;

	dp = ft_strsplit(*source_code, '\n');
	dp_head = dp;
	while (*dp)
	{
		processed_line = get_processed_line_asm_corewar(*dp);
		free(*dp);
		*dp = processed_line;
		dp++;
	}
	without_comments = join_cdp(dp_head, '\n');
	free_cdp(dp_head);
	ft_strpchar(&without_comments, '\n');
	free(*source_code);
	*source_code = without_comments;
}
