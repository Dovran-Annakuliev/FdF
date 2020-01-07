# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 17:09:20 by rfork             #+#    #+#              #
#    Updated: 2020/01/07 17:42:32 by rfork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -g
NAME = fdf
SRCS = main.c start.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I fdf.h
LIB = -L libft -lft -L sources/minilibx_macos -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

%.o: %.c
		$(GCC) -c $<

lib:
		make -C libft
		make -C sources/minilibx_macos

$(NAME): $(OBJS) lib
		$(GCC) $(OBJS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean
		make -C sources/minilibx_macos clean

fclean: clean
		rm -f $(NAME)
		make -C libft fclean
		make -C sources/minilibx_macos fclean

re: fclean all
