SRC 		= 	./main.c \
				./parsing.c \
				./ft_atoi.c \
				./ft_isdigit.c \
				./initialize.c \
				./execution.c \

OBJ		= ${SRC:.c=.o}

HEADER		= ./

CC 			= gcc

RM 			= rm -f

CFLAGS 		= -Wall -Werror -Wextra -g3

LDFLAGS 	= -lpthread

ifdef DEBUG
	CFLAGS += -fsanitize=address -g3
endif

NAME 		= philo

all:		$(NAME)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

debug:
	${MAKE} DEBUG=1

clean:
			@$(RM) $(OBJ)

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re