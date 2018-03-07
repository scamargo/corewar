/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struntil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:51:16 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/10 14:52:09 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_struntil(char *start_incl, char *end_excl)
{
	char	*output;

	if (end_excl == 0)
		return (ft_strdup(start_incl));
	output = ft_strnew(end_excl - start_incl);
	output = ft_strncpy(output, start_incl, end_excl - start_incl);
	return (output);
}
