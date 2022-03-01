SRCS		= $(shell find "./Srcs" -name "*c")
OBJS		= ${SRCS:.c=.o}
NAME		= fdf
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	@${CC} ${OBJS}

all : ${NAME}

compile : all
	./a.out test_maps/10-2.fdf

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o