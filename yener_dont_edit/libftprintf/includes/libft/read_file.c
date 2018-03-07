/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:49:57 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/03 22:57:28 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(char *path)
{
	int		fd;
	char	*contents;
	char	buffer;

	fd = open(path, O_RDONLY);
	contents = ft_strnew(0);
	if (fd == -1)
		return (0);
	while (read(fd, &buffer, 1))
		ft_strpchar(&contents, buffer);
	close(fd);
	return (contents);
}
