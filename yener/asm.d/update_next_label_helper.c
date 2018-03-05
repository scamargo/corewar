/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_next_label_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:53:59 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/04 23:58:19 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	update_next_label_helper_asm_corewar(char **line, int direct)
{
	int		index;
	char	*itoa_result;
	char	*label_head;

	label_head = ft_strchr(*line, ':');
	index = label_head - *line;
	itoa_result = ft_itoa(direct);
	while (*(*line + index) != ' ')
		ft_delete(line, *line + index);
	ft_addstr(line, *line + index, itoa_result);
	ft_strdel(&itoa_result);
}
