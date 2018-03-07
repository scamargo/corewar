/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_labels_asm_corewar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:59:43 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 16:37:29 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*check_for_label_asm_corewar(char *to_check)
{
	char	*supposed_label;

	supposed_label = ft_struntil2(to_check, '\t');
	if (ft_strchr(supposed_label, ':') == 0)
	{
		ft_strdel(&supposed_label);
		return (0);
	}
	return (supposed_label);
}

static void	append_labels_asm_corewar(char *label, int line_count,
		char **labels)
{
	char	*line_count_s;

	ft_strpstr(labels, label);
	line_count_s = ft_itoa(line_count);
	ft_strpstr(labels, line_count_s);
	ft_strpchar(labels, ' ');
	ft_strdel(&line_count_s);
}

char		*get_labels_asm_corewar(char *source_code)
{
	int		line_count;
	char	**dp;
	char	**dp_head;
	char	*labels;
	char	*label;

	line_count = 0;
	labels = ft_strnew(0);
	dp = ft_strsplit(source_code, '\n');
	dp_head = dp;
	while (*(dp + line_count))
	{
		if ((label = check_for_label_asm_corewar(*(dp + line_count))))
		{
			append_labels_asm_corewar(label, line_count, &labels);
			ft_strdel(&label);
		}
		line_count++;
	}
	free_cdp(dp_head);
	return (labels);
}
