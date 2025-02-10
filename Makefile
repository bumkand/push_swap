# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakand <jakand@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 22:27:56 by jakand            #+#    #+#              #
#    Updated: 2025/02/10 23:34:34 by jakand           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = push_swap.c main.c ft_atoi.c alghorithm.c ft_split.c \
		ft_strdup.c ft_substr.c operations_s_p.c operations_rot.c operations_rev.c \
		exe_moves.c calculate_operations.c exe_operations.c swap_two_three.c swap_four_five.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
# Command to make executable binary file

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re