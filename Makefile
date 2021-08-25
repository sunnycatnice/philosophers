# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaderi <rpaderi@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 18:14:17 by rpaderi           #+#    #+#              #
#    Updated: 2021/08/12 19:25:04 by rpaderi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HPATH = -Iincludes

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIR_SRCS = srcs
DIR_MINILIBFT= lib
DIR_PHILO = program
DIR_OBJS = objs
CURRENT_FOLDER = $(shell pwd)
OBJS_PATH = $(addprefix $(CURRENT_FOLDER)/, $(DIR_OBJS))

MINILIBFT_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_MINILIBFT))
PHILO_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_PHILO))

MINILIBFT_FILES =	check_by_char.c \
					ft_atoi.c \
					ft_putchar_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					is_digit.c \
					is_neg.c \
					is_space.c \

PHILO_FILES	=	eating.c \
				exit.c \
				forks.c \
				ft_printerr.c \
				init.c \
				main.c \
				messages.c \
				parser.c \
				utils.c \

SRCS_MINILIBFT = $(addprefix $(MINILIBFT_PATH)/, $(MINILIBFT_FILES))
SRCS_PHILO = $(addprefix $(PHILO_PATH)/, $(PHILO_FILES))
SRCS = $(SRCS_MINILIBFT) $(SRCS_PHILO)

OBJS_FILES = $(PHILO_FILES:.c=.o) $(MINILIBFT_FILES:.c=.o)
OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS_FILES))

all: $(NAME)

$(OBJS) : $(SRCS)
	-@$(CC) $(FLAGS) $(SRCS) -c
	mv *.o $(DIR_OBJS)

$(NAME) : $(OBJS)
	@echo Compiling: $(NAME)
	@$(CC) $(FLAGS) $(HPATH) $(OBJS) -o $(NAME)
	@echo Compiled successfully!

clean:
	@echo Deleting objects files...
	@rm -f $(OBJS)
	@echo Deleting done!

fclean: clean
	@echo Deleting $(NAME)...
	@rm $(NAME)
	@rm -rf *.o
	@echo Deleting done!

re: fclean all

.PHONY: all clean fclean re
