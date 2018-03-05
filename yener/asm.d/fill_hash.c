/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:59:52 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/05 00:11:37 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	check_line_whitespaces_asm_corewar(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\v')
			return (1);
		line++;
	}
	return (0);
}

static void	get_source_code_asm_corewar(char **file_string)
{
	char	**dp;
	char	**dp_head;
	char	*source_code;

	dp = ft_strsplit(*file_string, '\n');
	dp_head = dp;
	source_code = ft_strnew(0);
	while (*dp)
	{
		if (check_for_comment_asm_corewar(*dp) == 0 &&
			check_line_whitespaces_asm_corewar(*dp))
		{
			ft_strpstr(&source_code, *dp);
			ft_strpchar(&source_code, '\n');
		}
		dp++;
	}
	free_cdp(dp_head);
	free(*file_string);
	*file_string = source_code;
}

static char	*get_comment_asm_corewar(char *file_string)
{
	char	*comment;

	while (ft_strnequ(file_string, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		file_string = ft_strchr(file_string, '\n') + 1;
	file_string = ft_strchr(file_string, '"') + 1;
	comment = ft_struntil2(file_string, '"');
	return (comment);
}

static char	*get_name_asm_corewar(char *file_string)
{
	char	*name;

	while (ft_strnequ(file_string, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		file_string = ft_strchr(file_string, '\n') + 1;
	file_string = ft_strchr(file_string, '"') + 1;
	name = ft_struntil2(file_string, '"');
	return (name);
}

void	fill_hash_asm_corewar(t_as *hash)
{
	hash->new_path = get_new_path_asm_corewar(hash->old_path);
	hash->file_string = read_file(hash->old_path);
	hash->name = get_name_asm_corewar(hash->file_string);
	hash->comment = get_comment_asm_corewar(hash->file_string);
	get_source_code_asm_corewar(&(hash->file_string));
	hash->labels = get_labels_asm_corewar(hash->file_string);
	get_encoded_asm_corewar(&(hash->file_string));
	remove_comments_asm_corewar(&(hash->file_string));
	get_preprocessed_asm_corewar(&(hash->file_string));
	update_labels_asm_corewar(&(hash->file_string), hash->labels);
}
