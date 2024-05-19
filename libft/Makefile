# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 19:07:04 by vodebunm          #+#    #+#              #
#    Updated: 2024/05/19 22:41:29 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# List of source files
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
       ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
       ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
       ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c \
       ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c

# List of Bonus files
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
             ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
             ft_lstmap.c \

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to make the library
all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

# Rule to clean everything
fclean: clean
	$(RM) $(NAME)

# Rule to recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus