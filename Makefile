SRC 		= 	./main.c \
				./parsing.c \
				./ft_atoi.c \
				./ft_isdigit.c \
				./execution.c \
				./init_philo.c \
				./init_mutex.c \
				./time.c \
				./watcher.c \
				./ft_strncmp.c \
				./ft_free.c \

OBJ		= ${SRC:.c=.o}

HEADER		= ./

CC 			= clang

RM 			= rm -f

CFLAGS 		= -Wall -Werror -Wextra

LDFLAGS 	= -lpthread

ifdef DEBUG
	CFLAGS += -fsanitize=address
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