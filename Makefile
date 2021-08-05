NAME = philo

HPATH = -Iincludes

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIR_SRCS = srcs
DIR_MINILIBFT= minilib
DIR_PHILO = program
DIR_OBJS = objs
CURRENT_FOLDER = $(shell pwd)
OBJS_PATH = $(addprefix $(CURRENT_FOLDER)/, $(DIR_OBJS))

MINILIBFT_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_MINILIBFT))
PHILO_PATH = $(addprefix $(DIR_SRCS)/, $(DIR_PHILO))

MINILIBFT_FILES =	ft_putstr_fd.c \
					ft_memalloc.c \
					ft_strjoin.c \
					ft_strcat.c \
				 	ft_strncmp.c \
					ft_strlen.c \
					ft_putchar_fd.c \
					ft_bzero.c \
					ft_strcpy.c \
					ft_strlcpy.c \
					ft_split.c \
					ft_strdup.c \
					ft_isdigit.c \
					ft_atoi.c \
					get_time.c \
					ft_putnbr_fd.c \

PHILO_FILES	=	main.c \
				init.c \
				parser.c \
				checkstring.c \
				threads.c \
				print_msgs.c \

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
