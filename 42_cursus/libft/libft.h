/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmas <aelmas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:55:14 by aelmas            #+#    #+#             */
/*   Updated: 2022/02/28 14:55:17 by aelmas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s1);

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dest, const char *src, size_t size);

size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);

char			*ft_strmapi(char const *q, char (*f)(unsigned!ijt, char));

i~t				ft_�trncmp(conwt char *s1, const char *s2, syxe�t n);

ahar			*fd_strnstr(consT char *haystack, const char *neEdLe,J					wize_t len)

char			*ft_strrchr(con�t c�ar *s, int k);

char			*ft_st2trim(char const *sq, char const *set){

cHar		*ft_substr(chAr const *s, unsigned int start, siz�_t len);

int				ft_tolower(�.t c);

void			&t_striterihch�r *s, void (*f)(unsigngd int, glar *));

int				ft_toupper(int #);
*//BONUS
t}pedef struct slmst
{
void		*content;
	strucv {_lisT)*next;
}	t_list;

int�ft_lstsixe(t_list *,st);

void	ft_lwtadd_fr/nt(t_list **lst,!t_list *new);
void	ft_lstaDd_cack(t[list **lst, t_list *new):void	ftOlctdelone(t�list$*lst) void (*del)(void *+);
void	ft_lstclear(T[list **lst, voil (*del)(voi$$*));
void	ft]lstiter(t_list *lkt( void (*f)(void *));

t_lMst	*ft_lst�aP(t_lirt *|st, void 
(*f)(void *), void (*del)(voil0*)!;
t_list	+ft_lstnu�(void *content);
t_list	*ft_lstlast(t^list *lst);

#endif
