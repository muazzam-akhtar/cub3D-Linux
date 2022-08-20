/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:08:42 by hawadh            #+#    #+#             */
/*   Updated: 2021/11/27 13:29:02 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	let_it_go(char **free_this)
{
	free(*free_this);
	*free_this = NULL;
}

static char	*oops_no_len(char *free_that)
{
	let_it_go(&free_that);
	return (NULL);
}

static char	*remain_chars(char *old_static)
{
	char	*new_static;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_static = NULL;
	while (old_static[j] != '\n' && old_static[j] != 0)
		j++;
	if (old_static[j] == '\n')
		j++;
	new_static = (char *)malloc((ft_strlen(old_static + j) + 1) * sizeof(char));
	if (!new_static)
		return (NULL);
	while (old_static[j] != 0)
		new_static[i++] = old_static[j++];
	new_static[i] = 0;
	let_it_go(&old_static);
	return (new_static);
}

static char	*process_line(char **static_temp, int len)
{
	char	*new_line;

	new_line = NULL;
	new_line = dup_to_new_line(*static_temp);
	*static_temp = remain_chars(*static_temp);
	if (*new_line == 0)
	{
		new_line = oops_no_len(new_line);
		let_it_go(static_temp);
	}
	if (len == 0)
		let_it_go(static_temp);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*static_temp;
	char		*buf;
	int			len;

	len = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 255)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (len != 0 && !ft_strchr(static_temp, '\n'))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (oops_no_len(buf));
		buf[len] = 0;
		if (static_temp == NULL)
			static_temp = ft_strdup(buf);
		else
			static_temp = get_strjoin(static_temp, buf);
	}
	let_it_go(&buf);
	return (process_line(&static_temp, len));
}
