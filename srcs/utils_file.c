/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:09:10 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/12 14:59:34 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Only stores relevent lines in d->file
**/
int	store_data(t_data *d, char **input)
{
	int	i;
	int	j;

	d->file = (char **)ft_calloc(get_act_size(input) + 1, sizeof(char *));
	if (!d->file)
		return (EXIT_FAILURE);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (ft_strncmp(input[i], "", ft_strlen(input[i])))
			if (!check_line(input[i]))
				d->file[j++] = ft_strdup(input[i]);
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
