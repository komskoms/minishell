CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
NAME 	= libft.a
SRC		= \
	ft_atoi.c\
	ft_bias.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_charalloc.c\
	ft_ctoa.c\
	ft_intdup.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa_base.c\
	ft_itoa.c\
	ft_lltoa.c\
	ft_llutoa_base.c\
	ft_ltoa.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_stoa.c\
	ft_substr.c\
	ft_strdup.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_strchr.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_tolower_ptr.c\
	ft_tolower.c\
	ft_toupper_ptr.c\
	ft_toupper.c\
	ft_utoa_base.c\
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c
OBJ			= $(SRC:.c=.o)
SRC_EXTRA	= \
	ft_wheel_tools.c\
	ft_wheel.c\
	get_next_line.c\
	get_next_line_utils.c\
	init.c\
	stack.c\
	replace.c\
	prompt.c\
	dlist_utils.c\
	hashmap_utils0.c\
	hashmap.c\
	darray.c\
	converter0.c
OBJ_EXTRA	= $(SRC_EXTRA:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $? -o $@

$(NAME) : $(OBJ) $(OBJ_EXTRA)
	ar src $@ $?

.PHONY: all clean fclean re

all : $(NAME)

clean : 
	rm -f $(OBJ) $(OBJ_EXTRA)

fclean : clean
	rm -f $(NAME)

re : fclean all
