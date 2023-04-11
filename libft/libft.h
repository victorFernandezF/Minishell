/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:27:10 by victofer          #+#    #+#             */
/*   Updated: 2023/04/11 11:20:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

/* B O N U S */
typedef struct s_lst	t_lst;

typedef struct s_lst
{
	int		data;
	t_lst	*next;
}			t_lst;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//	S T R I N G   F U N C T I O N S

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_bzero(void *s, size_t n);
char	*ft_str_rev(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
char	**ft_split_2(char *str);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//	M E M O R Y   F U N C T I O N S

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

//	N U M B E R  S   F U N C T I O N S

int		ft_atoi(const char *str);
int		max(int *tab, unsigned int len);
int		min(int *tab, unsigned int len);
int		ft_pow(int x, int pow);

//	B A S E   C H A N G E   F U N C T I O N S

int		ft_atoi_base(char *str, int base);
int		ft_bin_to_dec(int num);

//	L I S T   F U N C T I O N S   ( B O N U S )
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_lst	*sort_list(t_lst *lst, int (*cmp)(int, int));


//	---- FT_PRINTF ----
int		ft_printf(char const *input, ...);
int		ft_print_char(int c);
int		ft_print_unsigned(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_string(char *s);
int		ft_print_int(int n);
int		ft_print_hexa(unsigned int num, char format);

//	---- GET_NEXT_LINE ----

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*get_line_gnl(char *str);
char	*save_rest(char *str);
char	*ft_join_free(char *buffer, char *buff);

char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_calloc_gnl(size_t count, size_t size);
#endif
