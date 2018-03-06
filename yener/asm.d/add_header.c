/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 20:35:35 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 13:59:33 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_prog_size_bytes_asm_corewar(char *source_code)
{
	unsigned int	*u_int_t;
	char			*char_t;
	char			*prog_size;

	u_int_t = (unsigned int*)malloc(sizeof(unsigned int) * 1);
	*u_int_t = get_total_byte_count_asm_corewar(source_code);
	char_t = (char*)u_int_t;
	prog_size = ft_strnew(0);
	append_byte_asm_corewar(&prog_size, char_t[3]);
	append_byte_asm_corewar(&prog_size, char_t[2]);
	append_byte_asm_corewar(&prog_size, char_t[1]);
	append_byte_asm_corewar(&prog_size, char_t[0]);
	free(u_int_t);
	ft_strpchar(&prog_size, '\n');
	return (prog_size);
}

static char	*get_comment_bytes_asm_corewar(t_as *hash)
{
	char	*comment;
	char	*comment_string;
	int		comment_length;

	comment = ft_strnew(0);
	comment_length = COMMENT_LENGTH + 1;
	comment_string = hash->comment;
	while (*comment_string && comment_length > 0)
	{
		append_byte_asm_corewar(&comment, *comment_string);
		comment_string++;
		comment_length--;
	}
	comment_length += 3;
	while (comment_length > 0)
	{
		append_byte_asm_corewar(&comment, 0);
		comment_length--;
	}
	ft_strpchar(&comment, '\n');
	return (comment);
}

static char	*get_name_bytes_asm_corewar(t_as *hash)
{
	char	*name;
	char	*name_string;
	int		prog_name_length;

	name = ft_strnew(0);
	prog_name_length = PROG_NAME_LENGTH + 1;
	name_string = hash->name;
	while (*name_string && prog_name_length > 0)
	{
		append_byte_asm_corewar(&name, *name_string);
		name_string++;
		prog_name_length--;
	}
	prog_name_length += 3;
	while (prog_name_length > 0)
	{
		ft_strpstr(&name, "0 ");
		prog_name_length--;
	}
	ft_strpchar(&name, '\n');
	return (name);
}

static char	*get_header_asm_corewar(t_as *hash)
{
	char	*header;
	char	*name;
	char	*prog_size;
	char	*comment;

	header = start_magic_number_asm_corewar();
	name = get_name_bytes_asm_corewar(hash);
	ft_strpstr(&header, name);
	prog_size = get_prog_size_bytes_asm_corewar(hash->file_string);
	ft_strpstr(&header, prog_size);
	comment = get_comment_bytes_asm_corewar(hash);
	ft_strpstr(&header, comment);
	ft_strdel4(&name, &prog_size, &comment, 0);
	return (header);
}

void		add_header_asm_corewar(t_as *hash)
{
	char	*header;

	header = get_header_asm_corewar(hash);
	ft_strpstr(&header, hash->file_string);
	free(hash->file_string);
	hash->file_string = header;
}
