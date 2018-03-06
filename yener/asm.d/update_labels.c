/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:15:24 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 18:12:20 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_byte_difference_asm_corewar(int start_line, int end_line,
		char *source_code)
{
	if (start_line > end_line)
	{
		ft_printf("START LINE: %d\nEND LINE: %d\n", start_line, end_line);
		return (-1 * get_byte_difference_asm_corewar(end_line, start_line, source_code));
	}
	if (start_line == end_line)
		return (0);
	return (get_byte_difference_helper_asm_corewar(start_line, end_line,
			source_code));
}

static int	get_label_line_asm_corewar(char *label, char *labels)
{
	while (*labels)
	{
		if (ft_strnequ(labels, label, ft_strlen(label)))
			return (ft_atoi(ft_strchr(labels, ':') + 1));
		labels = ft_strchr(labels, ' ') + 1;
	}
	return (-1);
}

static void	update_next_label_asm_corewar(char **line, char *labels,
	int line_count, char *source_code)
{
	char	*label;
	char	*parser;
	int		label_line;
	int		direct;

	parser = ft_strchr(*line, ':');
	parser++;
	label = ft_struntil2(parser, ' ');
	label_line = get_label_line_asm_corewar(label, labels);
	direct = get_byte_difference_asm_corewar(line_count, label_line, source_code);
	update_next_label_helper_asm_corewar(line, direct);
	ft_strdel(&label);
}


static void	update_single_line_label_asm_corewar(char **line, char *labels,
		int line_count, char *source_code)
{
	while (ft_strchr(*line, ':') != 0)
		update_next_label_asm_corewar(line, labels, line_count, source_code);
}

void		update_labels_asm_corewar(char **source_code, char *labels)
{
	char	**dp;
	char	*new_code;
	int		line_count;

	dp = ft_strsplit(*source_code, '\n');
	line_count = 0;
	while (*(dp + line_count))
	{
		update_single_line_label_asm_corewar(dp + line_count, labels,
				line_count, *source_code);
		line_count++;
	}
	new_code = join_cdp(dp, '\n');
	ft_strpchar(&new_code, '\n');
	free_cdp(dp);
	free(*source_code);
	*source_code = new_code;
}
