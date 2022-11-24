/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:09:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/24 21:34:21 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Only stores relevent lines in info->data->file
*
**	check_config_map();
*		Function to check for any new lines between map lines.
*		placed in 'utils_file_ext.c'
**/
int	store_data(t_info *info, char **input)
{
	int	i;
	int	j;

	info->data->file
		= (char **)ft_calloc(get_act_size(input) + 1, sizeof(char *));
	if (!info->data->file)
		return (EXIT_FAILURE);
	if (check_config_map(input))
	{
		free(info->data->file);
		info->data->file = NULL;
		free_split(input);
		err_return(3, info);
	}
	i = 0;
	j = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "", ft_strlen(input[i])))
			if (!check_line(input[i]))
				info->data->file[j++] = ft_strdup(input[i]);
		i++;
	}
	free_split(input);
	return (EXIT_SUCCESS);
}

/**
**	Returns Actual size of string without excess whitespaces
**/
static int	count_str_size(char *input)
{
	char	*temp;
	size_t	count;

	count = 0;
	temp = input;
	while (*temp)
	{
		if (temp == input)
			while (*temp && ft_isspace(*temp))
				temp++;
		while (*temp && *(temp + 1)
			&& ft_isspace(*temp) && ft_isspace(*(temp + 1)))
			temp++;
		if (*temp && ft_isspace(*temp) && *temp != ' ')
			temp++;
		if (*temp)
		{
			count++;
			temp++;
		}
	}
	return (count);
}

/**
**	Squashes lines by removing any excess whitespaces
**/
char	*squash(char *input)
{
	char	*out;
	char	*temp;
	size_t	len;
	int		i;

	i = 0;
	temp = input;
	len = count_str_size(input);
	out = (char *)ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (*temp)
	{
		if (temp == input)
			while (*temp && ft_isspace(*temp))
				temp++;
		while (*temp && *(temp + 1)
			&& ft_isspace(*temp) && ft_isspace(*(temp + 1)))
			temp++;
		if (*temp && ft_isspace(*temp) && *temp != ' ')
			temp++;
		if (*temp)
			out[i++] = *temp++;
	}
	return (out);
}

/**
**	Removes '\t' and '\v' from arrays
**/
char	**clean_whitespace(char **input)
{
	char	**tmp;
	char	*temp;
	size_t	i;

	i = 0;
	tmp = (char **)ft_calloc(ft_ptrptrlen(input) + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (input[i] && !check_if_map(input[i]))
	{
		temp = ft_strrmc(input[i], '\t');
		tmp[i] = ft_strrmc(temp, '\v');
		free(temp);
		i++;
	}
	while (input[i])
	{
		tmp[i] = ft_strdup(input[i]);
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

/**
**	Checks if array is the first line of map
**	is_digit && isspace
**/
int	check_if_map(char *input)
{
	char	*temp;

	temp = input;
	while (*temp)
	{
		if (!ft_isdigit(*temp) && !ft_isspace(*temp) && !ft_ismapicon(*temp))
			return (FALSE);
		temp++;
	}
	return (TRUE);
}
