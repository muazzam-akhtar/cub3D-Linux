# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:36:51 by hawadh            #+#    #+#              #
#    Updated: 2022/10/14 22:43:34 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	cub3D

LIBFT		=	libft.a

LIBFTDIR	=	./libft

GNL			=	get_next_line.a

GNLDIR		=	./get_next_line

SRCS		=	./srcs/main.c ./srcs/parse_file.c ./srcs/errors.c \
				./srcs/utils_parse.c ./srcs/utils_file.c ./srcs/memory_mngmnt.c \
				./srcs/window.c ./srcs/utils_hooks.c ./srcs/draw.c \
				./srcs/mouse.c ./srcs/hooks.c ./srcs/utils_file_ext.c \
				./srcs/parse_layout.c ./srcs/parse_map.c ./srcs/get_rgb.c \
				./srcs/config_xpm.c ./srcs/place_rgb.c ./srcs/rgb.c \
				./srcs/utils_draw.c ./srcs/mini_map.c ./srcs/utils_xpm.c \
				./srcs/player.c ./srcs/utils_minimap.c ./srcs/utils_memory_mngmnt.c \
				./srcs/moves.c ./srcs/wall_coll.c ./srcs/parse_spaces.c \
				./srcs/utils_str.c ./srcs/rays.c ./srcs/utils_math.c \
				./srcs/basic_movements.c ./srcs/edge_cases.c ./srcs/directions.c \
				./srcs/linux_osx_mouse.c ./srcs/utils_type.c


MLX			=	libmlx.a

#Checks current OS and determines which to flags to set
OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR		=	./minilibx_opengl
	MLXFLG		=	./libmlx.a -framework OpenGL -framework Appkit
	CFLAGS		+=	-D OSX
else
	MLXDIR		=	./minilibx_linux
	MLXFLG		=	./libmlx.a -lXext -lX11 -lm -lz
	CFLAGS		+=	-D LINUX
endif

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra -g3

${NAME}:	${OBJS}
			${MAKE} -C ${GNLDIR}
			${MAKE} -C ${MLXDIR}
			${MAKE} -C ${LIBFTDIR}
			cp ${LIBFTDIR}/${LIBFT} ./
			cp ${GNLDIR}/${GNL} ./
			cp ${MLXDIR}/${MLX} ./
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${GNL} ${MLXFLG} -o ${NAME}

all:	${NAME}

vg:		${NAME}
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3d file.cub

clean:
		rm -rf ${OBJS}
		rm -rf ${LIBFT}
		rm -rf ${GNL}
		rm -rf ${MLX}
		${MAKE} clean -C ${LIBFTDIR}
		${MAKE} clean -C ${MLXDIR}

fclean:	clean
		${MAKE} fclean -C ${LIBFTDIR}
		${MAKE} fclean -C ${GNLDIR}
		rm -rf ${NAME}

re: fclean all

.PHONY : all clean re fclean