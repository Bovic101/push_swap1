# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 00:40:14 by vodebunm          #+#    #+#              #
#    Updated: 2024/05/19 19:42:41 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Source files
SRCS = $(wildcard ./push_swap_src/*.c)

# Header files and paths
INCLUDE = include
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/
LIBFT_HEADER = libft/libft.h
PRINTF_HEADER = ft_printf/ft_printf.h

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Object files
OBJS = $(SRCS:.c=.o)

# All Rules
all: $(LIBFT) $(PRINTF) $(NAME)

# Link the final executable
$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -L$(PRINTF_PATH) -lftprintf -lft -o $(NAME)

# Build the printf library
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Compile object files from source files
./push_swap_src/%.o: ./push_swap_src/%.c $(LIBFT_HEADER) $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -c $< -o $@

# Clean object files and libraries
clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJS)

# Clean everything including the final executable
fclean: clean
	rm -f $(LIBFT) $(PRINTF) $(NAME)

# Recompile everything
re: fclean all

# Bonus target
bonus: all

# Phony targets
.PHONY: all clean fclean re bonus