CC		= gcc
CFLAG	= -Wall -Wextra -Werror
INC		= -I../inc
INC_LFT	= -I../lib/libft
NAME	= libminishell.a
SRC		= \
			main.c\
			minishell.c
OBJ		= $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAG) -c $(INC) $(INC_LFT) $? -o $@

$(NAME) : $(OBJ)
	ar src $@ $?

.PHONY: clean all fclean re

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
