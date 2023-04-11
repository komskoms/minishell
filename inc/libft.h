/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 08:54:55 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/06/01 10:51:50 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define CUSTOM_OPEN_MAX 255

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# define KEY 0
# define VALUE 1
# define HASH_SIZE 16

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_wheel
{
	void			*content;
	struct s_wheel	*next;
	struct s_wheel	*prev;
}					t_wheel;

typedef union		u_lld
{
	double			d;
	long long		ll;
}					t_lld;

typedef struct		s_bias
{
	unsigned int	bias;
	int				ll_size;
	int				real_size;
	int				unreal_size;
}					t_bias;

typedef struct		s_pair
{
	void			*key;
	void			*val;
	size_t			key_length;
}					t_pair;

typedef struct		s_hashmap
{
	struct s_dlist	**data;
	int				count;
}					t_hashmap;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_index(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_itoa_only_digit(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
										void (*del)(void *));
char				*ft_reverse(char *str, int len);
char				*ft_charalloc(size_t size, char c);
char				*ft_llutoa_base(unsigned long long num, int base);
char				*ft_utoa_base(unsigned int num, unsigned int base);
char				*ft_itoa_base(int num, int base);
int					ft_length_based_digit(int num, int base);
int					ft_length_based_lludigit(unsigned long long num, int base);
int					ft_length_based_udigit(unsigned int num,
															unsigned int base);
int					ft_length_digit(int num);
int					ft_abs(int num);
void				ft_toupper_ptr(char *c);
void				ft_tolower_ptr(char *c);
t_bias				*ft_new_bias(void);
unsigned long long	ft_get_full_bit(int length);
long long			ft_llabs(long long n);
int					ft_length_lldigit(long long num);
char				*ft_lltoa_only_digit(long long n);
char				*ft_lltoa(long long n);
int					ft_length_based_sdigit(unsigned short num, int base);
int					ft_length_based_cdigit(unsigned char num, int base);
char				*ft_stoa_base(unsigned short num, int base);
char				*ft_ctoa_base(unsigned char num, int base);
int					ft_length_cdigit(char num);
int					ft_length_sdigit(short num);
char				*ft_ctoa_only_digit(char num);
char				*ft_stoa_only_digit(short num);
long				ft_labs(long n);
int					ft_length_ldigit(long num);
char				*ft_ltoa_only_digit(long n);
char				*ft_ltoa(long n);
char				*ft_lutoa_base(unsigned long long num, int base);
t_wheel				*ft_new_wheel(void *content);
void				*ft_addlast_wheel(t_wheel **source, t_wheel *element);
void				*ft_addfront_wheel(t_wheel **source, t_wheel *element);
void				ft_drop_wheel(t_wheel **wheel, void (*del)(void *));
ssize_t				ft_wheel_length(t_wheel *source);
t_wheel				*ft_join_wheel(t_wheel *source, t_wheel *append);
void				ft_del_current_wheel(t_wheel **source);
t_wheel				*ft_pop_current_wheel(t_wheel **source);
int					*ft_intdup(int value);
int					get_next_line(int fd, char **line);
int					dispose_string(int fd, char **data,
													char **line, int offset);
void				*init(void **request, size_t size);
void				**init3(void ***request, size_t size);
void				*replace(void **out, void *src);
void				del_content(void *content);
void				show_prompt(void);
t_list				*pop_list(t_list **list);
t_list				*look_list(t_list *list, unsigned int offset);
char				*list_to_darray(char ***out, t_list *list);
t_list				*darray_to_list(t_list **list, char **darray);
void				drop_darray(char ***array);
void				*dlist_new(void *content);
void				*dlist_add_front(t_dlist **dlist, t_dlist *new);
void				*dlist_add_last(t_dlist **dlist, t_dlist *new);
void				dlist_clear(t_dlist **dlist, void (*del)(void *));
int					dlist_size(t_dlist *dlist);
t_dlist				*hashmap_update(t_hashmap *hashmap, t_pair *pair);
t_dlist				*hashmap_pick(t_hashmap *hashmap, char *key);
t_pair				*hashmap_pop(t_hashmap *hashmap, char *key);
void				hashmap_clear(t_hashmap **hashmap);
void				pair_clear(void *pair);
char				*pair_to_str(t_pair *pair);
char				*pair_element(int name_code, void *data);
t_hashmap			*init_hashmap(t_hashmap **out);
t_pair				*new_pair(char *str);
unsigned int		conv_hash(char *str);
void				*dlist_to_darray(char **darray, t_dlist *dlist);
char				**hashmap_to_darray(char ***darray, t_hashmap *hashmap);
t_hashmap			*darray_to_hashmap(t_hashmap **hashmap, char **darray);
int					darray_element_count(char **darray);
void				ft_tolower_str(char *str);
void				ft_toupper_str(char *str);

#endif
