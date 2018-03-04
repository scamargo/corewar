/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:18:09 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/22 15:12:43 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpchar(char **destination, char c)
{
	char	*string;

	string = ft_strdup("a");
	string[0] = c;
	ft_strpstr(destination, string);
	ft_strdel(&string);
}
