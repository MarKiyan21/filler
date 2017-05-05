#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 17:26:31 by mkyianyt          #+#    #+#              #
#    Updated: 2017/05/03 19:47:44 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bonus

SRC = bonus.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) -L ../libft/ -lft $(OBJ)

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)