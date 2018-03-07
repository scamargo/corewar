/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:52:47 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/03 22:57:12 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel4(char **to_del1, char **to_del2, char **to_del3,
		char **to_del4)
{
	if (to_del1)
		ft_strdel(to_del1);
	if (to_del2)
		ft_strdel(to_del2);
	if (to_del3)
		ft_strdel(to_del3);
	if (to_del4)
		ft_strdel(to_del4);
}
