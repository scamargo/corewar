/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:53:55 by ytuz              #+#    #+#             */
/*   Updated: 2018/03/06 15:42:25 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"

typedef struct	s_format
{
	char	*flags;
	int		width;
	int		precision;
	char	*arguments;
	char	conversion;
	int		is_special;
}				t_format;

int				ft_printf(const char *format, ...);

char			is_flag(char character);

char			is_argument(char character);

char			is_conversion(char character);

char			*skip_until_conversion(const char *format);

void			fill_flags(t_format *percent_handler, const char *format);

void			fill_width(t_format *percent_handler, const char *format);

void			fill_precision(t_format *percent_handler, const char *format);

void			fill_arguments(t_format *percent_handler, const char *format);

void			fill_conversion(t_format *percent_handler, const char *format);

void			delete_t_format(t_format **to_delete);

char			*skip_until_end(const char *format);

char			*convert_t_format(t_format *info,
					const char *format, va_list ap);

char			*printf_itoa(uintmax_t number, char conversion);

char			*printf_itoa_negative(intmax_t number, char conversion);

void			apply_precision_s(char **to_change, t_format *info);

char			*convert_as_is(const char *format);

char			*convert_char(t_format *info, va_list ap);

char			*convert_signed_number(t_format *info, va_list ap);

char			*convert_unsigned_number(t_format *info, va_list ap);

char			*convert_char_p(t_format *info, va_list ap);

char			*convert_wint_t(t_format *info, va_list ap);

char			*convert_wint_t(t_format *info, va_list ap);

char			*convert_wchar_t_p(t_format *info, va_list ap);

int				is_char(t_format *info);

int				is_unsigned_number(t_format *info);

int				is_signed_number(t_format *info);

int				is_char_p(t_format *info);

int				is_wint_t(t_format *info);

int				is_wchar_t_p(t_format *info);

void			apply_others(char **to_apply, t_format *info);

void			apply_flags(char **to_apply, t_format *info);

void			apply_width(char **to_apply, t_format *info);

void			apply_precision(char **to_apply, t_format *info);

void			apply_positive_width(char **to_apply, t_format *info);

void			apply_negative_width(char **to_apply, t_format *info);

void			cast_number(intmax_t *number, t_format *info);

char			*convert_percent(t_format *info);

void			apply_positive_width_space(char **to_apply, t_format *info);

void			cast_unsigned(uintmax_t *number, t_format *info);

void			apply_hash_to_p(char **to_apply);

#endif
