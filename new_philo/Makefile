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

SRCS			=	main.c \
					utils.c \
					exit.c \
					messages.c \
					init.c \
					forks.c \
					eating.c \
					ft_printerr.c \
					lib/check_by_char.c \
					lib/is_digit.c \
					lib/is_neg.c \
					lib/is_space.c \
					lib/ft_putnbr_fd.c \
					lib/ft_putstr_fd.c \
					lib/ft_putchar_fd.c \
					lib/ft_atoi.c \
					parser.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
LIBS			= -lpthread

NAME			= philo

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
