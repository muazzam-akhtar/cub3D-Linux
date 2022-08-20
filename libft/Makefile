# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 14:08:11 by makhtar           #+#    #+#              #
#    Updated: 2022/07/12 14:59:17 by hawadh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_itoa.c ft_memchr.c ft_split.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_strjoin.c \
	  ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c\
	  ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strmapi.c ft_strncmp.c \
	  ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	  ft_substr.c ft_tolower.c ft_toupper.c ft_isspace.c \
	  ft_ptrptrlen.c ft_strrmc.c ft_strcmp.c ft_ismapicon.c

OBJS	= ${SRCS:.c=.o}

BONUS_S	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	  ft_lstsize.c ft_lstnew.c ft_lstmap.c
BONUS_O	= ${BONUS_S:.c=.o}


CC = gcc -g3

RM = rm -f


CFLAGS = -Wall -Wextra -Werror


.c.o : ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME} : 	${OBJS} ${INCLUDE}
		ar -rcs ${NAME} ${OBJS}


all: 		${NAME}

bonus:		${NAME} ${BONUS_O}
		ar -rc ${NAME} ${BONUS_O}


clean:
		${RM} ${OBJS} ${BONUS_O}


fclean: clean
			${RM} ${NAME}


re :		fclean all

rebonus:	fclean bonus
