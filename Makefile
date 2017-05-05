#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 17:26:19 by mkyianyt          #+#    #+#              #
#    Updated: 2017/05/03 19:49:30 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

SRC = add.c check.c filler.c find.c length.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mBuilding archive babyyyy...wait...\033[0m"
	@make -C libft/
	@make -C visual/
	@gcc $(FLAGS) -o $(NAME) -L libft/ -lft $(OBJ)
	@echo "\033[33;1mAbra Kadabra!!!\033[0m"

.c.o:
	@echo "\033[34;3mGeting funky with\033[0m $<"
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -f $(OBJ)
	@make -C libft/ clean
	@make -C visual/ clean

fclean: clean
	@echo "\033[31mRemoving exe...\033[0m"
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C visual/ fclean

re: fclean all

norme:
	norminette $(SRC)