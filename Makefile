NAME = fdf
SRCS = $(shell find "./Srcs" -d 1 -name "*c")
OBJS = ${SRCS:.c=.o}
LIBFT = ./Libft/libft.a
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar csr

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C ./Libft
	$(CC) ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all : ${NAME}

clean :
	#${NAME}
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re .c.o