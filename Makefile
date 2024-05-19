# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 00:40:14 by vodebunm          #+#    #+#              #
#    Updated: 2024/05/19 18:25:50 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = include
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/
LIBFT_HEADER = libft/libft.h
PRINTF_HEADER = ft_printf/ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

# All Rules
all: $(LIBFT) $(PRINTF)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

# Rule to clean everything

fclean: clean
	rm -f $(LIBFT) $(PRINTF)

# Rule to recompile
re: fclean all

bonus: all

# Phony targets
.PHONY: all clean fclean re bonus