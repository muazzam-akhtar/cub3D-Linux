/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:13:55 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/25 19:22:39 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Getting valid keys for the map
**/
int	valid_key(int c)
{
	if (c == '0')
		return (c);
	else if (c == '1')
		return (c);
	else if (c == 'N')
		return (c);
	else if (c == 'W')
		return (c);
	else if (c == 'S')
		return (c);
	else if (c == 'E')
		return (c);
	else if (c == 'D')
		return (c);
	return (FALSE);
}

/**
**	Takes actual size of 2D array
**/
size_t	get_act_size(char **input)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "", ft_strlen(input[i])))
			count++;
		i++;
	}
	return (count);
}

/**
**	Gets initial size of file in Number of lines
**/
int	get_size(t_info *info, char *str)
{
	char	*temp;
	size_t	count;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		err_return(0, info);
	count = 0;
	temp = ft_memset((char *)ft_calloc(1, sizeof(char)), 0, 1);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		count++;
	}
	if (temp)
		free(temp);
	close(fd);
	return (count);
}

/**
**	To check if the given file is a directory
**/
int	isdir(char *str)
{
	int		fd;
	int		ret;
	char	buf[1];

	fd = open(str, O_RDONLY);
	ret = read(fd, buf, 1);
	if (ret == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

/**
**	Confirm Correct File extension
**/
int	compare_ext(char *str)
{
	char	*tmp;

	tmp = str;
	tmp = ft_strrchr(str, '.');
	if (*tmp && !strcmp(tmp, ".cub"))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
