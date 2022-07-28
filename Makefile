# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eward <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 15:00:45 by eward             #+#    #+#              #
#    Updated: 2022/07/28 15:00:47 by eward            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	= 	main.c init.c error.c utils.c algo.c threads.c

HEADER	=	philo.h

CC		=	gcc

FLAGS	=	-g -Wall -Werror -Wextra -I .

RM		=	rm -f

OBJ		=	$(SRCS:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c  $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
