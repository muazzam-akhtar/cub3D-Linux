/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:17:11 by hawadh            #+#    #+#             */
/*   Updated: 2022/06/22 20:12:11 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*get_strjoin(char *s1, char *s2);
char	*dup_to_new_line(char *s1);
void	let_it_go(char **free_this);

#endif
