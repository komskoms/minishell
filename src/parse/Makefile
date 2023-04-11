CC			= gcc
CFLAG		= -Wall -Wextra -Werror
INC_LFT		= -I../../lib/libft
INC_MSHL	= -I../../inc
NAME		= libparse.a
SRC			= \
			parse.c\
			parse_element.c\
			parse_token.c\
			parse_build.c\
			parse_syntax.c\
			parse_standard.c\
			parse_split_semicolon.c\
			parse_cmd_set.c\
			parse_legacy.c\
			parse_exchange.c\
			parse_transform_env.c\
			cmd_check.c\
			test_show_struct.c
OBJ		= $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAG) -c $(INC_LFT) $(INC_MSHL) $? -o $@

$(NAME) : $(OBJ)
	ar src $@ $?

.PHONY: clean all fclean re test_mshl

all : $(NAME)

clean :
	$(MAKE) clean -C ../../lib/libft
	rm -f $(OBJ)

fclean : clean
	rm -f ../../lib/libft/libft.a
	rm -f $(NAME)

re : fclean all
