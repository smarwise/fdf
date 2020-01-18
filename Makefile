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

OBJ = obj/rotate.o obj/shift.o obj/get_height.o obj/dimensions.o\
		obj/free_t_points.o obj/main.o obj/key_set.o obj/read_from_file.o\
		obj/drawline.o obj/coordinates.o obj/print.o obj/zoom.o

$(NAME): $(OBJ)
	$(FLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a

all:
	make -C libft/
	make $(NAME)

$(OBJ): obj/%.o: srcs/%.c
		$(FLAGS) -c srcs/$*.c -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)
	
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	
re: fclean all
