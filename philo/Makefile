# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 12:31:24 by gabriela          #+#    #+#              #
#    Updated: 2024/12/04 20:05:27 by gabriela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#
NAME = philo
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -lpthread
HEADER = -I ./include

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#
FILES = \
	philo.c\
	page_philo.c\
	validations.c\
	utils.c\
	message.c\
	clear_memory.c\
	init.c\
	func_utils.c\
	get_set.c\
	dinner_utils.c\
	dinner_start.c\
	monitor.c\
	time.c\

OBJS = $(FILES:.c=.o)

#******************************************************************************#
#				     				RULES      								   #
#******************************************************************************#
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re