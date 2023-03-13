# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 19:07:53 by llion             #+#    #+#              #
#    Updated: 2022/08/02 16:54:40 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC			= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
PRE			= ./srcs/
SRCS		= ${addprefix ${PRE}, ${SRC}}
OBJS		= ${SRCS:.c=.o}
HEAD		= ./includes/
AR			= ar rc
RM			= rm -f
LIB			= ranlib


all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) 
			$(LIB) $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean 
