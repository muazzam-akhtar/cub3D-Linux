/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:18:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/24 21:51:47 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Function to check if any misconfiguration in map
*
*	First loop skips any remaining config lines
*
*	Second loop, loops to first line of map skipping whitespaces
*
*	Finaly begin to check map lines:
*		EXIT_SUCCESS if no misconfig
**/
static int	check_map_lines(char **input)
{
	int	i;

	i = 0;
	while (!check_map_config_lines(input[i]) || check_line(input[i]))
	{
		if (check_line(input[i]) && ft_strlen(input[i]) > 1)
			return (EXIT_FAILURE);
		i++;
	}
	while (input[i])
	{
		if (check_line(input[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
**	Checks file to skip config to start parse from map
**/
int	check_config_map(char **input)
{
	static int	count;
	char		**temp;

	count = 0;
	temp = input;
	while (temp && *temp)
	{
		count += check_config_lines(*temp);
		if (*temp && check_line(*temp) && ft_strlen(*temp) > 1)
			return (EXIT_FAILURE);
		if (++temp && count == 6)
			return (check_map_lines(temp));
	}
	return (EXIT_SUCCESS);
}

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
char	*check_tabs(char *input)
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
