/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cdp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 22:38:50 by ytuz              #+#    #+#             */
/*   Updated: 2018/02/25 22:53:00 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_cdp(char **dp, char separator)
{
	char	*joined;

	joined = ft_strnew(0);
	while (*dp)
	{
		if (*joined)
			ft_strpchar(&joined, separator);
		ft_strpstr(&joined, *dp);
		dp++;
	}
	return (joined);
}
