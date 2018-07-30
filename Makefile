# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarwise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 08:14:41 by smarwise          #+#    #+#              #
#    Updated: 2018/07/28 13:49:27 by smarwise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = gcc -Wall -Wextra -Werror -Wuninitialized

OBJ = rotate.o shift.o get_height.o dimensions.o free_t_points.o main.o key_set.o read_from_file.o drawline.o coordinates.o print.o zoom.o

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
