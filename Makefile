# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:15:05 by dgiurgev          #+#    #+#              #
#    Updated: 2023/11/04 13:50:27 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf.c

BONUS_SOURCES = ft_printf_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME) $(OBJECTS_BONUS)

re: fclean all

bonus: all $(OBJECTS_BONUS)
	ar rcs $(NAME) $(OBJECTS_BONUS)

.PHONY: all clean fclean re bonus
