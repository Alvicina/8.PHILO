# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 11:10:14 by alvicina          #+#    #+#              #
#    Updated: 2023/12/26 10:50:52 by alvicina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c parse.c error_msg.c create_philo.c free.c threads.c \
	  philo_routine.c msg_print.c controller_routine.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ) philo.h
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

execute:
	./$(NAME) 0 1 1 1 0

clean:
	rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all execute clean fclean re lib
