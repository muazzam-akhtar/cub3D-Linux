/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:18:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/12 15:03:13 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Checks if line only contains spaces
**/
int	check_line(char *input)
{
	char	*temp;

	temp = input;
	while (*temp)
	{
		if (!ft_isspace(*temp))
			return (FALSE);
		temp++;
	}
	return (TRUE);
}

/**
**	Modified len to count a '\t' == Tab as 4
**/
static size_t	get_tab_size(char *input)
{
	size_t	count;
	size_t	tab;

	tab = 0;
	count = 0;
	while (input[count])
	{
		if (input[count] == '\t')
		{
			tab += 4;
			count++;
		}
		else
			count++;
	}
	return (count + tab);
}

/**
**	Checks map for tabs and replaces them with ' ' == 32;
**/
static char	*check_tabs(char *input)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	temp = (char *)ft_calloc(get_tab_size(input) + 1, sizeof(char));
	while (input[i])
	{
		k = j;
		if (input[i] == '\t')
			while (j < k + 4)
				temp[j++] = ' ';
		else if (input[i] != '\n')
			temp[j++] = input[i];
		i++;
	}
	return (temp);
}

/**
**	Removes excess whitespace ' '
*	check_if_map();		If not first line of map
*								keep squashing
*	check_tabs();		Replaces '\t' with 4 ' '
*								spaces
**/
char	**squash_lines(char **file, char **input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
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
