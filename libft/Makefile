# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 19:07:04 by vodebunm          #+#    #+#              #
#    Updated: 2024/05/02 03:40:31 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strjoin.c \
			ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_putstr.c \
			
BONUSSRC 	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\

OBJS	=	$(SRCS:%.c=%.o)

OBJSBONUS = ${BONUSSRC:%.c=%.o}

CC 		=	gcc

FLAGS	= -Wall -Wextra -Werror

RM 		= rm -f

all: $(NAME)

$(NAME):
		cc $(FLAGS) -c $(SRCS) -I./
		ar rc $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJSBONUS)
		ar rc $(NAME) $(OBJS) $(OBJSBONUS)

clean:
		rm -f $(OBJS) $(OBJSBONUS)

fclean:	clean
		rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re