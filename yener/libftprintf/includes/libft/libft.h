/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:49:19 by ytuz              #+#    #+#             */
/*   Updated: 2018/02/25 22:52:49 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *string);

char				*ft_strdup(const char *string);

int					ft_isdigit(int test);

int					ft_isalpha(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_atoi(const char *string);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strcat(char *string1, const char *string2);

char				*ft_strncpy(char *dest, const char *src, size_t len);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(const char *big, const char *little);

int					ft_strcmp(const char *string1, const char *string2);

int					ft_strncmp(const char *string1,
							const char *string2, size_t size);

void				*ft_memset(void *data, int c, size_t len);

void				ft_bzero(void *data, size_t size);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memchr(const void *s, int c, size_t size);

int					ft_memcmp(const void *data1,
							const void *data2, size_t size);

void				*ft_memmove(void *dest, const void *src, size_t len);

void				*ft_memccpy(void *dest,
								const void *src, int c, size_t size);

char				*ft_strncat(char *string1,
								const char *string2, size_t size);

char				*ft_strnstr(const char *big,
								const char *little, size_t len);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

void				ft_putchar(char c);

void				ft_putstr(char const *string);

void				ft_putnbr(int number);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *string, int fd);

void				ft_putnbr_fd(int number, int fd);

void				ft_putendl(char const *string);

void				ft_putendl_fd(char const *string, int fd);

char				*ft_strnew(size_t size);

void				ft_strdel(char **string);

void				ft_strclr(char *string);

int					ft_strequ(char const *string1, char const *string2);

char				*ft_strmap(char const *string, char (*f)(char));

char				*ft_strmapi(char const *string, char
						(*f)(unsigned int, char));

void				ft_striter(char *string, void (*f)(char *));

void				ft_striteri(char *string, void (*f)(unsigned int,
									char *));

int					ft_strnequ(char const *string1, char const *string2,
						size_t size);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **data);

char				*ft_strsub(char const *string, unsigned int
						start, size_t size);

char				*ft_strjoin(char const *string1, char const *string2);

char				*ft_strtrim(char const *string);

char				**ft_strsplit(char const *string, char c);

char				*ft_itoa(int number);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_strpstr(char **destination, char *source);

void				ft_strpchar(char **destination, char c);

void				ft_putnbr2(int c);

void				ft_putchar2(char c);

char				*ft_struntil(char *start_incl, char *end_excl);

void				ft_reassign(char **reassignee, char **deleted);

void				ft_memdel4(void **address1, void **address2,
					void **address3, void **address4);

char				*ft_joincdp(char **double_pointer, char separator);

char				*ft_struntil2(char *start, char separator);

void				ft_repchar(char *string, char old, char new);

void				ft_delete(char **head, char *to_del);

void				ft_addchar(char **head, char *location, char to_add);

void				ft_addstr(char **head, char *location, char *to_add);

void				free_cdp(char **dp);

char				*join_cdp(char **dp, char separator);

#endif
