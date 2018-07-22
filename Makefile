# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarwise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 08:14:41 by smarwise          #+#    #+#              #
#    Updated: 2018/07/22 15:37:13 by smarwise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = gcc -Wall -Wextra -Werror

OBJ = main.o key_set.o read_from_file.o split_char.o drawline.o coordinates.o print_map.o

$(NAME): $(OBJ)
	$(FLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a

all:
	make -C libft/
	make $(NAME)

$(OBJ): %.o: %.c
	$(FLAGS) -c $*.c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
