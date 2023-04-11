CC			= gcc
CFLAG		= -Wall -Wextra -Werror
INC_LFT		= -I../../lib/libft
INC_MSHL	= -I../../inc
NAME		= libbuiltin.a
SRC			= \
			echo.c\
			cd.c\
			pwd.c\
			env.c\
			export.c\
			unset.c\
			exit.c
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
