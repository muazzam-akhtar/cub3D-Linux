# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:36:51 by hawadh            #+#    #+#              #
#    Updated: 2022/09/29 16:25:30 by hawadh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

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
				./srcs/moves.c ./srcs/wall_coll.c


MLX			=	libmlx.a

MLXDIR		=	./minilibx_opengl

MLXFLG		=	./libmlx.a -framework OpenGL -framework Appkit

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -g3

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