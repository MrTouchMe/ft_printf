# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:15:05 by dgiurgev          #+#    #+#              #
#    Updated: 2023/12/13 17:26:17 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ft_printf.c ft_parse.c ft_functions.c



OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME):	 $(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)



clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
