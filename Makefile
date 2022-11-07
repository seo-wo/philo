# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seowokim <seowokim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:45:57 by seowokim          #+#    #+#              #
#    Updated: 2022/11/07 19:51:42 by seowokim         ###   ########seoul.kr   #
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
	@echo "\033[0;34m\t===============USAGE==============="
	@echo "\t./philo (4 ~ 5 integer inputs)"
	@echo "\trange of inputs should be 0 < n < 2147483648, without any sign"

clean :
	@$(RMDIR) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all help clean fclean re