# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 16:40:37 by hawadh            #+#    #+#              #
#    Updated: 2022/06/22 16:49:14 by hawadh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS =	get_next_line.c\
		get_next_line_utils.c\

CFLAGS = -g3 -c -Wall -Werror -Wextra 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(CFLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re