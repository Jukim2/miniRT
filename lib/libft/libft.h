/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:11:19 by jukim2            #+#    #+#             */
/*   Updated: 2023/10/01 13:03:22 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_file
{
	int				fd;
	struct s_line	*line;
	struct s_file	*next_file;
	struct s_file	*prev_file;
}	t_file;

typedef struct s_line
{
	char			*str;
	struct s_line	*next_line;
	struct s_line	*prev_line;
}	t_line;

int				ft_isdigit(int s);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_file			*find_file(int fd, t_file *file_list);
int				make_line_node(t_file *file);
int				make_file_node(int fd, t_file **file_list);
int				find_newline(int idx, char *buffer);
char			*ft_strnjoin(char *str1, char *str2, int start_idx, int end_idx);
char			*get_next_line(int fd);
char			*read_file(int fd, char *buffer, t_file *file);
int				make_line(int rbyte, t_line *current_line, char *buffer);
int				push_line(t_line *current_line, char *buffer, int start, int end);
void			free_all(char *buffer, t_line *line, t_file *file, t_file **file_list);

#endif