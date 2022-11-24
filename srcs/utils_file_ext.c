/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:18:58 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/23 19:01:52 by hawadh           ###   ########.fr       */
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
		i++;
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
	static char	xpm[5][3] = {"NO", "SO", "WE", "EA", ""};
	static char	colours[3][2] = {"C", "F", ""};
	char		**temp;
	int			count;
	int			i;

	count = 0;
	temp = input;
	while (temp && *temp)
	{
		i = 0;
		while (xpm[i][0])
		{
			if (*temp && !ft_strncmp(*temp, xpm[i], 2))
				count++;
			i++;
		}
		i = 0;
		while (colours[i][0])
		{
			if (*temp && !ft_strncmp(*temp, colours[i], 1))
				count++;
			i++;
		}
		if (++temp && count == 5)
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
