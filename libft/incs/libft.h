/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:07:51 by femaury           #+#    #+#             */
/*   Updated: 2018/06/28 14:37:02 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include "ft_gnl.h"
# include "../ft_printf/incs/libftprintf.h"

typedef struct	s_list
{
	void			*content;
	void			*content_ptr;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

float			ft_sqrt(float nb);
int				ft_pow(int n, int power);
int				ft_abs(int nb);

void			ft_setupcase(char *s);
void			ft_setlowcase(char *s);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base);
char			*ft_imaxtoa_base(intmax_t n, int base);
char			*ft_uimaxtoa_base(uintmax_t n, int base);
int				ft_atoi(const char *str);
int				ft_strisonly(const char *str, const char *ref);
int				ft_strisonlyc(const char *str, const char ref);
int				ft_strisdigit(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

size_t			ft_strlen(const char *s);
size_t			ft_wstrlen(wchar_t *ws);
size_t			ft_wcharlen(wchar_t wc);
size_t			ft_strtabsize(char **s);
size_t			ft_strtablen(char **s);
size_t			ft_strtablen_at(char **s, int i, int j);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strdupto(const char *s1, char ref);
char			*ft_strndup(const char *s1, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strchrrev(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strhasc(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			ft_strdel(char **as);
void			ft_tabdel(void **tab, size_t len);
void			ft_strclr(char *s);
void			ft_strnclr(char *s, size_t len);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			**ft_strsplit(char const *s, char c);
char			*ft_strnew(size_t size, unsigned char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(char const *s1, char const *s2, size_t len);
char			*ft_strjoin_split(char const *s1, char const *s2, char split);
char			*ft_strtrim(char const *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putlst(t_list *lst);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstfind_content(t_list *lst, void *ref);
t_list			*ft_lstfind_size(t_list *lst, size_t ref);
t_list			*ft_lstcpy(t_list **alst);
size_t			ft_lstsize(t_list *lst);
void			ft_lstprepend(t_list **alst, t_list *new);
void			ft_lstappend(t_list **alst, t_list *new);
void			ft_lstrev(t_list **alst);
void			ft_lstdel(t_list **alst);
void			ft_lstdelfirst(t_list **alst);
int				ft_lstdellast(t_list **alst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
