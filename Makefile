# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 17:09:20 by rfork             #+#    #+#              #
#    Updated: 2020/02/29 20:04:29 by rfork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror
NAME = fdf
SRCS = sources/main.c \
       sources/start.c \
       sources/atoi_base.c \
       sources/draw_image.c \
       sources/errors.c \
       sources/key.c \
       sources/brez.c \
       sources/rot.c \
       sources/shift.c \
       sources/read_map.c \
       sources/shift_map.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I includes/fdf.h \
	includes/key.h

ifeq ($(OS),Windows_NT)
        detected_OS := Windows
else
        detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
        #LIB += -L./libs/glad/ -lglad -ldl  -lGL -L./libs/glfw/src/ -lglfw3 \
        -lXrandr -lXrender -lXi -lXfixes -lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp
        LIBMAKE := minilibx/minilibx
        LIB :=  -L libft -lft -L minilibx -lmlx_Linux  -lXrandr -lXrender -lXi -lXfixes \
        -lXxf86vm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lm
endif
ifeq ($(detected_OS),Darwin)
        #LIB = -L./libs/glad/ -lglad -L./libs/glfw/src/ -lglfw3      # Mac OS X
        #LIBRARIES += -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
        LIBMAKE := minilibx/minilibx_macos
        LIB = -L libft -lft -L minilibx -lmlx -framework OpenGL -framework Appkit
endif

all: $(NAME)

%.o: %.c
		$(GCC) -c $<

lib:
		make -C libft
		make -C minilibx/minilibx

$(NAME): $(OBJS) lib
		$(GCC) $(OBJS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
		make -C libft fclean
		make -C minilibx/minilibx clean

re: fclean all
