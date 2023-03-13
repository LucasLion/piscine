# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 15:21:16 by llion             #+#    #+#              #
#    Updated: 2022/08/04 11:32:44 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

NAME		= do-op

RM			= rm -f

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRC         = do-op.c functions.c operators.c




all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
