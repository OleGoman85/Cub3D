/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:46:28 by ogoman            #+#    #+#             */
/*   Updated: 2024/08/08 11:42:00 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>

/* Implementation of linked list */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Vector with x and y coordinates */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putnbr_fd(int n, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putchar_fd(char c, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *src);
void		*ft_memset(void *ptr, int value, size_t num);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isdigit(int input);
int			ft_isalpha(int input);
void		ft_bzero(void *s, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isalnum(int c);
size_t		ft_strlen(const char *s);
int			ft_isascii(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_isprint(int c);
size_t		ft_strlcat(char *dest, const char *src, size_t detsize);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strrchr(const char *str, int character);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_free_matrix(char ***m);
int			ft_strrncmp(const char *s1, const char *s2, size_t n);
int			ft_matrixlen(char **m);
char		**ft_extend_matrix(char **in, char *newstr);
int			ft_countchar(char *s, char c);
t_vector	ft_newvector(int x, int y);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(void *content);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		trim_spaces(char *line, int *col_start, int *col_end);

/*
--------BONUS--------
*/
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif