# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 17:09:20 by rfork             #+#    #+#              #
#    Updated: 2020/02/25 19:15:49 by dovran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -g
NAME = fdf
SRCS = main.c start.c atoi_base.c draw_image.c errors.c key.c read_map.c shaolin_wu.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I fdf.h key.h

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	#LIB += -L./libs/glad/ -lglad -ldl  -lGL -L./libs/glfw/src/ -lglfw3 \
	-lXrandr -lXrender -lXi -lXfixes -lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp
	LIBMAKE := sources/minilibx
	LIB :=  -L libft -lft -L sources/minilibx -lmlx_Linux  -lXrandr -lXrender -lXi -lXfixes \
	-lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lm
endif
ifeq ($(detected_OS),Darwin)  
	#LIB = -L./libs/glad/ -lglad -L./libs/glfw/src/ -lglfw3      # Mac OS X
	#LIBRARIES += -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
	LIBMAKE := sources/minilibx_macos
	LIB = -L libft -lft -L sources/minilibx -lmlx -framework OpenGL -framework Appkit
endif

all: $(NAME)

%.o: %.c
		$(GCC) -c $<

lib:
		make -C libft
		make -C sources/minilibx

$(NAME): $(OBJS) lib
		 $(GCC) $(OBJS)  $(LIB)   -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
		make -C libft fclean
		make -C sources/minilibx clean

re: fclean all
