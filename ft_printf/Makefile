# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 03:02:11 by vodebunm          #+#    #+#              #
#    Updated: 2024/02/18 06:37:44 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f


# List of source files
SRCS = ft_characater_printf.c ft_conversion_specifier.c ft_calculate_digit_base.c ft_strlen.c ft_putstr_fd.c \
			ft_int_dec_number_print.c ft_pointer_printf.c ft_printf.c ft_str_printf.c ft_putchar_fd.c ft_pointer.c\

OBJS = $(SRCS:.c=.o)

# All Rules
# Rule to make the library
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 

# Rule to clean everything
fclean: 
	$(MAKE) clean
	rm -f $(NAME)

# Rule to recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re 