# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: moeinrz <moeinrezaei330@gmail.com>                                    #
#                                                                              #
#    Created: 2022/11/11 10:46:04 by moeinrz                                   #
#    Updated: 2023/03/03 17:18:16 by moeinrz                                   #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
NAME_Bonus  = checker
CC          = cc
FLAGS       = -Wall -Wextra -Werror
INCLUDES    = ./include/
SRC         = $(shell find ./src -name "ft_lib.c" -o -name "ft_min_max.c"\
				-o -name "ft_operators_??.c" -o -name "ft_pop_push.c"\
				-o -name "ft_presort.c" -o -name "ft_sort_?digit.c"\
				-o -name "ft_sort_big.c" -o -name "ft_split.c"\
				-o -name "get_next_line_bonus.c" -o -name "get_next_line_utils_bonus.c"\
				-o -name "ft_init_??.c" -o -name "ft_sort_big_utils_0?.c"\
				-o -name "push_swap.c" -type f)
OBJ         = $(SRC:.c=.o)
SRC_Bonus   = $(shell find ./src -name "ft_lib.c" -o -name "ft_min_max.c"\
				-o -name "ft_operators_??.c" -o -name "ft_pop_push.c"\
				-o -name "ft_presort.c" -o -name "ft_sort_?digit.c"\
				-o -name "ft_sort_big.c" -o -name "ft_split.c"\
				-o -name "get_next_line_bonus.c" -o -name "get_next_line_utils_bonus.c"\
				-o -name "ft_init_??.c" -o -name "ft_sort_big_utils_0?.c"\
				-o -name "checker_bonus.c" -type f)
OBJ_Bonus   = $(SRC_Bonus:.c=.o)

all: $(NAME)
bonus: $(NAME_Bonus)
%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME_Bonus): $(OBJ_Bonus)
	$(CC) $(OBJ_Bonus) -o $(NAME_Bonus)
	
clean:
	rm -f $(OBJ) $(OBJ_Bonus)

fclean: clean
	rm -f $(NAME) $(NAME_Bonus)

re: fclean all

.PHONY:		all clean fclean re bonus
