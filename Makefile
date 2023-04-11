CC			= gcc
CFLAG		= -Wall -Wextra -Werror -fsanitize=address
NAME		= minishell
LIB_MS		= ./src/libminishell.a
LIB_MAIN	= ./src/tool/libmain.a
LIB_PARSE	= ./src/parse/libparse.a
LIB_BTIN	= ./src/builtin/libbuiltin.a
LIB_FT		= ./lib/libft/libft.a

$(NAME) :
	$(MAKE) -C ./lib/libft
	$(MAKE) -C ./src/tool
	$(MAKE) -C ./src/parse
	$(MAKE) -C ./src/builtin
	$(MAKE) -C ./src
	$(CC) -o $@  $(LIB_MS) $(LIB_MAIN) $(LIB_PARSE) $(LIB_BTIN) $(LIB_FT) -ltermcap

.PHONY: clean all fclean re $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./lib/libft
	$(MAKE) clean -C ./src/tool
	$(MAKE) clean -C ./src/parse
	$(MAKE) clean -C ./src/builtin
	$(MAKE) clean -C ./src

fclean : clean
	rm -f ./lib/libft/libft.a
	rm -f ./src/tool/libmain.a
	rm -f ./src/parse/libparse.a
	rm -f ./src/builtin/libbuiltin.a
	rm -f ./src/libminishell.a
	rm -f $(NAME)

re : fclean all
