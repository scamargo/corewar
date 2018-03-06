/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:37:24 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 14:12:34 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	check_first_four_bytes_corewar(char *file)
{
	char			first_four[4];
	unsigned int	*u_int_t;
	char			*char_t;
	int				fd;
	char			ret_status;

	u_int_t = (unsigned int *)malloc(sizeof(unsigned int) * 1);
	*u_int_t = COREWAR_EXEC_MAGIC;
	char_t = (char*)u_int_t;
	fd = open(file, O_RDONLY);
	ret_status = 1;
	if (fd == -1)
		ret_status = 0;
	if (ret_status)
	{
		read(fd, &first_four, 4);
		if (first_four[0] != char_t[3] || first_four[1] != char_t[2] ||
			first_four[2] != char_t[1] || first_four[3] != char_t[0])
			ret_status = 0;
	}
	free(u_int_t);
	return (ret_status);
}

static char	check_file_corewar(char *file)
{
	char	*last_period;

	last_period = ft_strrchr(file, '.');
	if (ft_strequ(last_period, ".cor") == 0)
	{
		ft_error(file);
		ft_error(": not a .cor file\n");
		return (0);
	}
	if (check_first_four_bytes_corewar(file) == 0)
	{
		ft_error(file);
		ft_error(": corrupt or inaccessible file\n");
		return (0);
	}
	return (1);
}

static char	print_usage_corewar(void)
{
	ft_error("Usage:\t./corewar options (-n n1) champion1 (-n n2) champion2 ...\n");
	ft_error("Options:\t-dump nbr_cycles:\tdump the core on STDOUT and exit after nbr_cycles\n");
	ft_error("\t\t-n number:\t\toptional. set the number for the player\n");
	return (0);
}	

char		check_args_corewar(int ac, char **av)
{
	if (ac < 3)
		return (print_usage_corewar());
	av++;
	while (*av)
	{
		if (check_file_corewar(*av) == 0)
			return (0);
		av++;
	}
	return (1);
}
