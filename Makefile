# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:45:57 by seowokim          #+#    #+#              #
#    Updated: 2022/11/09 15:08:10 by seowokim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_DIR = ./srcs/
HEADER_DIR = ./includes/
OBJS_DIR = ./objs

SRCS = $(wildcard $(SRCS_DIR)*.c)
vpath %.c $(SRCS_DIR)
OBJS = $(foreach SRCS, $(SRCS), $(OBJS_DIR)/$(notdir $(SRCS:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
RMDIR = rm -rf

all : $(NAME)

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) -o $@

help :
	@echo "\033[0;34m\t=========================USAGE========================="
	@echo "\033[0;33m\t./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat] "
	@echo "\033[0;35m\tnumber_of_philosophers: \033[0;36mThe number of philosophers and also the number of forks."
	@echo "\033[0;35m\ttime_to_die (in milliseconds): \033[0;36mIf a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die."
	@echo "\033[0;35m\ttime_to_eat (in milliseconds): \033[0;36mThe time it takes for a philosopher to eat. During that time, they will need to hold two forks."
	@echo "\033[0;35m\ttime_to_sleep (in milliseconds): \033[0;36mThe time a philosopher will spend sleeping."
	@echo "\033[0;35m\tnumber_of_times_each_philosopher_must_eat (optional argument): \033[0;36mIf all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops.\n\t\t\t\t\t\t\t\t\tIf not specified, the simulation stops when a philosopher dies."
	@echo "\033[0;31m\tREMIND : range of inputs should be 0 < n < 2147483648, without any signs"

clean :
	@$(RMDIR) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all help clean fclean re