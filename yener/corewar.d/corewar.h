/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:32:35 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 14:14:38 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libftprintf/includes/ft_printf.h"
# include "op.h"

char	check_args_corewar(int ac, char **av);

void	corewar(char **av);

#endif
