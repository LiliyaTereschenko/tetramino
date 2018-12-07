# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkihn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 11:56:12 by kkihn             #+#    #+#              #
#    Updated: 2018/11/29 12:34:35 by kkihn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = fillit

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) -c main.c ft_*.c
	gcc -o $(NAME) main.o ft_*.o -L libft/ -lft

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
