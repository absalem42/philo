# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 14:25:59 by absalem           #+#    #+#              #
#    Updated: 2024/01/14 20:35:23 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo

SRCS =		main.c parsing.c utiles.c utiles2.c destroy.c \
			philo_init.c routin.c thread_handel.c\

OBJS =		$(SRCS:.c=.o)

CC	 =		cc
CFLAGS =	-Wall -Wextra -Werror -pthread #-g3 -fsanitize=address

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean 
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean
