# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absalem < absalem@student.42abudhabi.ae    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 14:25:59 by absalem           #+#    #+#              #
#    Updated: 2024/01/03 16:00:26 by absalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo

SRC 			=  main.c utiles.c\

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re