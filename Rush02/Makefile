NAME = "rush-02"
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ${wildcard *.c}
OBJET = ${FILES:.c=.o}

all: $(NAME)

${NAME}: ${OBJET}
	${CC} ${CFLAGS} ${OBJET} -o ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
