# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 11:35:32 by davgalle          #+#    #+#              #
#    Updated: 2024/04/09 14:40:09 by davgalle         ###   ########.fr        #
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
	  src/data_init.c \
	  src/auxiliar.c \
	  src/init.c \
	  src/threads.c \
	  src/threads_sync.c

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
