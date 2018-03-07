/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:31:33 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/06 21:19:57 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(const char c)
{
	if (c == ' ' || c == '\n' ||
		c == '\t')
		return (1);
	else
		return (0);
}

static int	whitespace_check(const char *string)
{
	while (*string)
	{
		if (is_whitespace(*string) == 0)
			return (1);
		string++;
	}
	return (0);
}

static	int	trimmed_length(const char *string)
{
	char	*beginning;
	char	*end;

	beginning = (char *)string;
	end = (char *)(string + ft_strlen(string) - 1);
	while (is_whitespace(*beginning) == 1 && *beginning)
		beginning++;
	while (is_whitespace(*end) == 1 && *end)
		end--;
	return ((int)(end - beginning + 1));
}

char		*ft_strtrim(char const *string)
{
	char	*result;
	int		index;
	int		length;

	if (string == 0)
		return (0);
	if (whitespace_check(string) == 0)
		return (ft_strdup(""));
	length = trimmed_length(string);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (is_whitespace(*string) == 1)
		string++;
	while (index < length)
	{
		result[index] = *string;
		index++;
		string++;
	}
	result[index] = '\0';
	return (result);
}
