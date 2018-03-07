/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:33:32 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/17 14:12:35 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel4(void **address1, void **address2,
		void **address3, void **address4)
{
	if (address1 != 0)
		ft_memdel(address1);
	if (address2 != 0)
		ft_memdel(address2);
	if (address3 != 0)
		ft_memdel(address3);
	if (address4 != 0)
		ft_memdel(address4);
}
