# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 14:25:59 by absalem           #+#    #+#              #
#    Updated: 2024/01/10 16:11:17 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo

SRCS =		main.c parsing.c utiles.c utiles2.c destroy.c \
			philo_init.c \

OBJS =		$(SRCS:.c=.o)

CC	 =		cc
CFLAGS =	-Wall -Wextra -Werror -pthread

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean 
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean
