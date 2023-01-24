# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrezaei <mrezaei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 15:58:29 by mrezaei           #+#    #+#              #
#    Updated: 2022/12/02 18:28:41 by mrezaei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	libft.a
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	../include
OBJ				=	$(SRC:.c=.o)
SRC 			=	$(shell find . -name "ft_str.c" -o -name "ft_isalnum.c" -o -name "ft_strtrim.c"\
					-o -name "ft_isprint.c" -o -name "ft_memcmp.c" -o -name "ft_putchar_fd.c" \
					-o -name "ft_split.c" -o -name "ft_strlcat.c" -o -name "ft_strncmp.c" \
					-o -name "ft_substr.c" -o -name "ft_atoi.c" -o -name "ft_isalpha.c" \
					-o -name "ft_itoa.c" -o -name "ft_memcpy.c" -o -name "ft_putendl_fd.c" \
					-o -name "ft_strchr.c" -o -name "ft_strlcpy.c" -o -name "ft_strnstr.c" \
					-o -name "ft_tolower.c" -o -name "ft_bzero.c" -o -name "ft_isascii.c" \
					-o -name "ft_memccpy.c" -o -name "ft_memmove.c" -o -name "ft_putnbr_fd.c" \
					-o -name "ft_strdup.c" -o -name "ft_strlen.c" -o -name "ft_strrchr.c" \
					-o -name "ft_toupper.c" -o -name "ft_calloc.c" -o -name "ft_isdigit.c" \
					-o -name "ft_memchr.c" -o -name "ft_memset.c" -o -name "ft_putstr_fd.c" \
					-o -name "ft_strjoin.c" -o -name "ft_strmapi.c" -o -name "ft_lstlast.c" \
					-o -name "ft_lstadd_back.c" -o -name "ft_lstadd_front.c" -o -name "ft_lstclear.c" \
					-o -name "ft_lstdelone.c" -o -name "ft_lstiter.c" -o -name "ft_lstmap.c" \
					-o -name "ft_lstnew.c" -o -name "ft_lstsize.c" -type f)

all: $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@
	
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
