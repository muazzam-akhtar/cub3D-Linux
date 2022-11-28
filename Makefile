# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:36:51 by hawadh            #+#    #+#              #
#    Updated: 2022/11/28 15:43:39 by hawadh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			=	\033[0;31m

BLACK		=	\033[1;30m

WHITE		=	\033[1;37m

BLUE		=	\033[1;34m

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
				./srcs/basic_movements.c ./srcs/doors.c ./srcs/directions.c \
				./srcs/linux_osx_mouse.c ./srcs/utils_type.c ./srcs/parse_rgb_utils.c \
				./srcs/raycasting.c ./srcs/utils_dda_math.c ./srcs/gun_image.c \
				./srcs/angle.c ./srcs/color.c ./srcs/utils_minimap_ext.c ./srcs/mini_map_rot.c \
				./srcs/utils_door.c ./srcs/utils_line_check.c

MLX			=	libmlx.a

#Checks current OS and determines which to flags to set
OS:= ${shell uname}
ifeq (${OS},Darwin)
	MLXDIR		=	./minilibx_opengl
	MLXFLG		=	./libmlx.a -framework OpenGL -framework Appkit
	CFLAGS		+=	-D OSX
else
	MLXDIR		=	./minilibx_linux
	MLXFLG		=	./libmlx.a -lXext -lX11 -lm
	CFLAGS		+=	-D LINUX
endif

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS 		+= -Wall -Werror -Wextra -g3

${NAME}:	${OBJS}
			${MAKE} -C ${GNLDIR}
			${MAKE} -C ${MLXDIR}
			${MAKE} -C ${LIBFTDIR}
			cp ${LIBFTDIR}/${LIBFT} ./
			cp ${GNLDIR}/${GNL} ./
			cp ${MLXDIR}/${MLX} ./
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${GNL} ${MLXFLG} -o ${NAME}

all:	${NAME}
	@echo "${BLACK}  ${RED}WKkK${BLACK}                                                                                         ${RED}xX${BLACK}   "
	@echo "${RED}XK0xxX${BLACK}                                                                                         ${RED}xk0KN"
	@echo "${RED}xloxK${BLACK}                                                                                         ${RED}N0dllk"
	@echo "${RED}OoodOX${BLACK}                                       ${BLUE}WNXK0OOO0KNW${BLACK}                                    ${RED}N0xold0"
	@echo " ${RED}X0Oxdx00dx0N${BLACK}                             ${BLUE}WKOdolccc::;;:lxK${BLACK}                            ${RED}XOdx0OddxOKX${BLACK} "
	@echo "   ${RED}NKxlloooox0X${BLACK}                         ${BLUE}N0dodkO000OOkdc,..'c${BLACK}                        ${RED}NKkdoooolokKN${BLACK}   "
	@echo "     ${RED}X0xoooolcldOX${BLACK}                     ${BLUE}NkdxOXWWWWNXXKOdc,.. .c${BLACK}                   ${RED}N0kocclooodk0N${BLACK}     "
	@echo "       ${RED}NKOd:;;:cldkK${BLACK}                  ${BLUE}NkoxOXWMMWNXKK0Oxl,.   .c${BLACK}                ${RED}XOxolc:;;cx0XN${BLACK}       "
	@echo "         ${RED}NKo,';ccloox0${BLACK}                ${BLUE}Xo:lOXWWWX0Okxdol;'.    'O${BLACK}            ${RED}NKkdollcc;';xKN${BLACK}         "
	@echo "           ${RED}Xkc,,:lcccldO${BLACK}              ${BLUE}Kl,l0XXNKOxoloool:'..   .x${BLACK}          ${RED}N0xolcclc:,;lOX${BLACK}           "
	@echo "            ${RED}NKxc,,:ccloodk${BLACK}            ${BLUE}Xo:xK0OOOOxc,ckOdl:,'...,O${BLACK}         ${RED}Kxoollcc:,,c${BLACK}               "
	@echo "              ${RED}N0x:;::ccodxO${BLACK}           ${BLUE}Nxlc,....,locoxc.....'''lX${BLACK}       ${RED}NKkxdlc::;;cx${BLACK}                "
	@echo "                ${RED}NOocc::coxOO0${BLACK}         ${BLUE}WOl.  .....oOo'   .....;k${BLACK}      ${RED}NK0OOxoc::cco${BLACK}                  "
	@echo "                  ${RED}X0kdollloxOO0${BLACK}       ${BLUE}Nxl;. ..',:ll:.   ...,,;k${BLACK}    ${RED}NK0Okxocloodk0X${BLACK}                  "
	@echo "                    ${RED}KxcclloodxkO0${BLACK}      ${BLUE}0ooolclll;.....',,;:c;:${BLACK}   ${RED}NK0OkxooollccxK${BLACK}                    "
	@echo "                ${RED}NKOxl:;;;:cooodkO00${BLACK}     ${BLUE}Xx:,',,,'.'... .,;;cx${BLACK}  ${RED}NK00Oxdoooc:;;;:lx${BLACK}                   "
	@echo "         ${RED}XOkkxdol:;;;,,;::;:lodddxkOOK${BLACK}   ${BLUE}0c'.,cdkOOxc.  ...l${BLACK}  ${RED}KOOkxddxolc;;:;,,;;;:${BLACK}                 "
	@echo "        ${RED}Xd;;;;;;,,,,:cdkkddxocldxdddk0N${BLACK}   ${BLUE}o;';lx0Okkx:.....${BLACK}  ${RED}N0xdodxdlcoxdokkdc${RED}:,,,,;;;;;;oK${BLACK}        "
	@echo "       ${RED}WO:;;;;;:clok0XN${RED}WNXK0xc:ldxxooON${BLACK}    ${BLUE}c;:lodoool:'..'${BLACK}   ${RED}Nkooxkdl:cx0KXN${BLACK} ${RED}NX0xol:;;,,,,;xN${BLACK}       "
	@echo "       ${RED}N0xxxxkO0KXN${RED}WMMMMMWN${RED}Xd;;::clollkX${BLACK}    ${BLUE}llodxxxoc;,'.${BLACK}   ${RED}Xkllllc::;;oKNW${BLACK}                         "
	@echo "                          ${RED}W0c;;;ldoc;;:dK${RED}N${BLACK}   ${BLUE}kxdOKXk:;:${BLACK}   ${RED}N0dc;;:odl:;;cOW${BLACK}                          "
	@echo "                          ${RED}Xo::cxX${RED}NKd;,;lxOK${BLACK}           ${RED}0XXKOxl:,,o0NXkl:;lK${BLACK}                          "
	@echo "                         ${RED}Xdcclk${RED}NMMW0l,:lxO00K${BLACK}         ${RED}NK00Oxo:,cON${BLACK}  ${RED}NOlc:oK${BLACK}                         "
	@echo "                         ${RED}KxodO${RED}NMMMMNO:,cdkO00KN${BLACK}      ${RED}NK00Okdl,;xNW${BLACK}   ${RED}N0dod0W${BLACK}                        "
	@echo "                          ${RED}NXN${RED}WMMMMMW${RED}Xd,,codxO00X${RED}WMMW${RED}XK0Okdol,'lKW${BLACK}      ${RED}NXXNW${BLACK}                        "
	@echo "                                     ${RED}Kl.,clodkO00KK00Okdolc,.:ON${BLACK}                                    "
	@echo "                                      ${RED}O;.;llloodxOOkdoolll:',xXW${BLACK}                                    "
	@echo "                                      ${RED}Xd'';::cokKN${BLACK} ${RED}XOdc:::,.c0W${BLACK}                                     "
	@echo "                                       ${RED}0:.':oOX${BLACK}       ${RED}0dc,.'xN${BLACK}                                      "
	@echo "                                       ${RED}Xd,ckX${BLACK}           ${RED}0l'c0W${BLACK}                                      ${RED}"
	@echo ""
	@echo "                               ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ "
	@echo "                              ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"
	@echo "                              ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"
	@echo "                              ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"
	@echo "                              ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"
	@echo "                               ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ "
	@echo "                                                                       ${WHITE}"
	@cat authors

vg:		all
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3d tester.cub

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

leak:
		bash leaks.sh

.PHONY : all clean re fclean