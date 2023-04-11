CC			= gcc
CFLAG		= -Wall -Wextra -Werror
INC_LFT		= -I../../lib/libft
INC_MSHL	= -I../../inc
NAME		= libmain.a
SRC			= \
			error_handle.c signal_handler.c\
			prompt_control.c\
			termcap_control00.c termcap_control01.c termcap_control02.c\
			termcap_control03.c\
			token_manage00.c token_manage01.c token_manage02.c\
			token_to_process.c\
			proc_executor00.c proc_executor01.c proc_executor_pipe.c\
			proc_post_manage.c proc_builtin.c\
			redirect_handler.c\
			debug_print00.c
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
