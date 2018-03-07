/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reassign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:32:46 by ytuz              #+#    #+#             */
/*   Updated: 2018/01/15 12:40:55 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reassign(char **reassignee, char **deleted)
{
	ft_strdel(reassignee);
	*reassignee = ft_strdup(*deleted);
	ft_strdel(deleted);
}
