# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 10:46:04 by mrezaei           #+#    #+#              #
#    Updated: 2023/02/25 17:16:37 by mrezaei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
NAME_Bonus  = checker
CC          = cc
FLAGS       = -Wall -Wextra -Werror
INCLUDES    = ./include/
SRC         = $(shell find ./src -name "ft_*.c" -o -name "get_next_line_utiles.c" -o -name "get_next_line.c" -o -name "push_swap.c" -type f)
OBJ         = $(SRC:.c=.o)
SRC_Bonus   = $(shell find ./src -name "ft_*.c" -o -name "get_next_line_utiles.c" -o -name "get_next_line.c" -o -name "checker.c" -type f)
OBJ_Bonus   = $(SRC_Bonus:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ) -o $(NAME)

bonus: $(NAME_Bonus)

$(NAME_Bonus): $(OBJ_Bonus)
	$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ_Bonus) -o $(NAME_Bonus)

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_Bonus)

fclean: clean
	rm -f $(NAME) $(NAME_Bonus)

re: fclean all bonus

.PHONY: all clean fclean re bonus