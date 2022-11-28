# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:45:57 by seowokim          #+#    #+#              #
#    Updated: 2022/11/28 14:12:20 by seowokim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_DIR = ./srcs
HEADER_DIR = ./includes/
OBJS_DIR = ./objs

vpath %.c $(SRCS_DIR)


SRCS = acting.c \
	message.c \
	parsing.c \
	philo.c \
	thread.c \

OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJ))
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
RMDIR = rm -rf

all : $(NAME)
	
$(NAME) : $(OBJS)
	@echo "\033[0;34m====Compiling :\033[0;33m" $@ "\033[0;34m===="
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) -o $@
	@echo "\033[0;33m" $@ "HAS BEEN CREATED"


$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

help :
	@echo "\033[0;34m\t=========================USAGE========================="
	@echo "\033[0;33m\t./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat] "
	@echo "\033[0;35m\tnumber_of_philosophers: \033[0;36mThe number of philosophers and also the number of forks."
	@echo "\033[0;35m\ttime_to_die (in milliseconds): \033[0;36mIf a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die."
	@echo "\033[0;35m\ttime_to_eat (in milliseconds): \033[0;36mThe time it takes for a philosopher to eat. During that time, they will need to hold two forks."
	@echo "\033[0;35m\ttime_to_sleep (in milliseconds): \033[0;36mThe time a philosopher will spend sleeping."
	@echo "\033[0;35m\tnumber_of_times_each_philosopher_must_eat (optional argument): \033[0;36mIf all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops.\n\t\t\t\t\t\t\t\t\tIf not specified, the simulation stops when a philosopher dies."
	@echo "\033[0;31m\tREMIND : range of inputs should be 1 < n < 2147483648"

h : help

clean :
	@echo "\033[0;31mREMOVE OBJECTIVE FILES"
	@$(RMDIR) $(OBJS_DIR)

fclean : clean
	@echo "\033[0;31mREMOVE $(NAME)"
	@$(RM) $(NAME)

re : fclean all

.PHONY : all help h clean fclean re