/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:47:28 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/22 13:22:11 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpstr(char **destination, char *source)
{
	char	*new;

	new = ft_strjoin(*destination, source);
	ft_strdel(destination);
	*destination = new;
}
