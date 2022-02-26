SRCS		= $(shell find "." -name "*c")
#OBJS		= ${SRCS:.c=.o}
#BONUS_OBJS  = ${BONUSES:.c=.o}
NAME		= fdf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	@${AR} ${NAME} ${OBJS}

#bonus : ${BONUS_OBJS}
#	@${AR} libft.a ${BONUS_OBJS}


all : ${NAME}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o