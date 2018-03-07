/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_encoded.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:38:17 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 17:07:26 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_encoded_line_asm_corewar(char *line)
{
	char	*line_head;
	char	is_label;

	line_head = line;
	is_label = 0;
	while (*line && *line != '\t')
	{
		if (*line == ':')
			is_label = 1;
		line++;
	}
	if (is_label == 0)
	{
		while (*line_head == '\t')
			line_head++;
		return (ft_strdup(line_head));
	}
	return (ft_strdup(ft_strchr(line_head, '\t') + 1));
}

void	get_encoded_asm_corewar(char **source_code)
{
	char	*encoded;
	char	**dp;
	char	**dp_head;
	char	*new;

	dp = ft_strsplit(*source_code, '\n');
	dp_head = dp;
	while (*dp)
	{
		new = get_encoded_line_asm_corewar(*dp);
		free(*dp);
		*dp = new;
		dp++;
	}
	encoded = join_cdp(dp_head, '\n');
	ft_strpchar(&encoded, '\n');
	free_cdp(dp_head);
	free(*source_code);
	*source_code = encoded;
}
