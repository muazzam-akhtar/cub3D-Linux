/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:24:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/25 20:25:32 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Removes excess whitespace ' '
*
*	First check		:	If at beginning, if empty line, return error
*
*	check_if_map();		If not first line of map keep squashing
*
*	check_tabs();		Replaces '\t' with 4 ' ' spaces
*
**/
char	**squash_lines(t_info *info, char **file, char **input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (i == 0 && check_line(input[i]))
		{
			free(file);
			file = NULL;
			free_split(input);
			err_return(3, info);
		}
		if (!check_if_map(input[i]))
			file[i] = squash(input[i]);
		else if (ft_strchr(input[i], '\t'))
			file[i] = check_tabs(input[i]);
		else if (ft_strchr(input[i], '\n'))
			file[i] = ft_substr(input[i], 0, ft_strlen(input[i]) - 1);
		else
			file[i] = ft_strdup(input[i]);
		i++;
	}
	return (file);
}

/**
**	Reads and stores file contents using get_next_lines();
**/
static char	**extract_file(t_info *info, char *str, int size)
{
	char	*temp;
	char	**out;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		err_return(0, info);
	out = (char **)ft_calloc(size + 1, sizeof(char *));
	temp = (char *)ft_calloc(1, sizeof(char));
	if (!temp || !out)
		return (NULL);
	i = 0;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		if (temp)
			out[i++] = ft_strdup(temp);
	}
	free(temp);
	close(fd);
	return (out);
}

/**
**	Cleans file contents from excess whitespaces and stores in 2D array
*	clean_whitespaces();	Removes \t
*	squash();				Removes excess ' '
*	store_data();			Stores in 2D Array
**/
static int	clean_file(t_info *inf, char **input)
{
	char	**tmp;
	char	**file;

	tmp = clean_whitespace(input);
	if (input)
		free_split(input);
	if (!tmp)
		return (EXIT_FAILURE);
	file = (char **)ft_calloc(ft_ptrptrlen(tmp) + 1, sizeof(char *));
	if (!file)
		return (EXIT_FAILURE);
	file = squash_lines(inf, file, tmp);
	if (tmp)
		free_split(tmp);
	if (store_data(inf, file))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
**	Reads and extracts contents of file
*	Size = size of 2d Array
**/
static int	ft_reading(t_info *info, char *str)
{
	int		size;
	char	**temp;

	size = get_size(info, str);
	if (size <= 0)
		err_return(1, info);
	temp = extract_file(info, str, size);
	if (!temp)
		return (EXIT_FAILURE);
	if (clean_file(info, temp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
**	Parses/Reads and checks file for validity
**/
void	check_map(t_info *info, char *str)
{
	int	i;

	i = 0;
	if (isdir(str) && ft_strchr(str, '.'))
	{
		if (compare_ext(str))
			err_return(3, info);
	}
	else
		err_return(3, info);
	if (ft_reading(info, str))
		err_return(1, info);
	if (parse_arg(info->data->file, info))
		err_return(3, info);
	printf("\n");
	while (info->data->map[i])
		printf("Map	:	%s\n", info->data->map[i++]);
	printf("\n");
	printf("Reading/Cleaning and Parsing Complete\n");
}
