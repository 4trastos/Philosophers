# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 11:35:32 by davgalle          #+#    #+#              #
#    Updated: 2024/04/01 18:10:35 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

LIB = ar rcs

SRC = src/main.c \
	  src/error.c \
	  src/checker.c \
	  src/create_nodes.c \
	  src/auxiliar.c \
	  src/init.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

.PHONNY: all clean fclean re
