/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:43:28 by ytuz              #+#    #+#             */
/*   Updated: 2017/12/07 21:49:55 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *string, char c)
{
	int	count;

	count = 0;
	while (*string)
	{
		if (*string == c)
			string++;
		else
		{
			count++;
			while (*string != c && *string)
				string++;
		}
	}
	return (count);
}

static int	word_length(char const *string, char c)
{
	int	count;

	count = 0;
	while (*string && *string != c)
	{
		count++;
		string++;
	}
	return (count);
}

static void	fill_output(char ***output, int index, char const *string, char c)
{
	int	inner_index;

	(*output)[index] =
		(char *)malloc(sizeof(char) * (word_length(string, c) + 1));
	if ((*output)[index] == 0)
	{
		(*output) = 0;
		return ;
	}
	inner_index = 0;
	while (*string && *string != c)
	{
		(*output)[index][inner_index] = *string;
		string++;
		inner_index++;
	}
	(*output)[index][inner_index] = '\0';
	return ;
}

static void	malloc_output(char ***output, const char *string, char c)
{
	*output = (char **)malloc(sizeof(char *)
							* (word_count(string, c) + 1));
}

char		**ft_strsplit(char const *string, char c)
{
	char	**output;
	int		output_index;

	output_index = 0;
	if (string == 0)
		return (0);
	malloc_output(&output, string, c);
	if (output == 0)
		return (0);
	while (*string)
	{
		if (*string == c)
			string++;
		else
		{
			fill_output(&output, output_index, string, c);
			if (output == 0)
				return (0);
			while (*string != c && *string)
				string++;
			output_index++;
		}
	}
	output[output_index] = 0;
	return (output);
}
