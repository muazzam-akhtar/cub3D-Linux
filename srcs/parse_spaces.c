/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:41:07 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/03 17:08:43 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	top_row_spaces(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (ft_isspace(str[i][j]))
		{
			if (str[i + 1] != NULL && str[i + 1][j])
			{
				if (str[i + 1][j] != '1' && !ft_isspace(str[i + 1][j]))
					return (EXIT_FAILURE);
				j++;
			}
			else
				return (EXIT_FAILURE);
		}
		else
			j++;
	}
	return (EXIT_SUCCESS);
}

int	bot_row_spaces(char **str)
{
	int	i;
	int	j;

	i = ft_ptrptrlen(str) - 1;
	j = 0;
	while (str[i][j])
	{
		if (ft_isspace(str[i][j]))
		{
			if (str[i - 1] != NULL && str[i - 1][j])
			{
				if (str[i - 1][j] != '1' && !ft_isspace(str[i - 1][j]))
					return (EXIT_FAILURE);
				j++;
			}
			else
				return (EXIT_FAILURE);
		}
		else
			j++;
	}
	return (EXIT_SUCCESS);
}

/**
**	map: 2d string of the map.
**	str: string which needs to be parsed.
**	index: the current index of the map which needs to be parsed.
**	i: the iteration of each character in the string.
**	signal: Has one value among the values: 0, 1, 2.
	0: Indicates that if the character is the space, then it needs to be checked
		from all the four directions- top, bottom, left, right.
	1: Indicates that if the character is the space, then it needs to be checked
		for only three directions- top, bottom, right.
	2: Indicates that if the character is the space, then it needs to be checked
		for only three directions- top, bottom, left.
**/

static int	check_spaces(t_str *p, int index, int signal)
{
	if (p->str[p->i] && ft_isspace(p->str[p->i]))
	{
		if ((index - 1 >= 0) && (p->map[index - 1][p->i] != '1'
			&& !ft_isspace(p->map[index - 1][p->i])))
			return (EXIT_FAILURE);
		if ((index + 1 < get_2d_len(p->map))
			&& (p->map[index + 1][p->i] != '1'
			&& !ft_isspace(p->map[index + 1][p->i])))
			return (EXIT_FAILURE);
		if (signal == 0 || signal == 1)
		{
			if ((p->i + 1) < ft_strlen_int(p->str) && p->str[p->i + 1] != '1'
				&& !ft_isspace(p->str[p->i + 1]))
				return (EXIT_FAILURE);
		}
		if (signal == 0 || signal == 2)
		{
			if ((p->i - 1) >= 0 && p->str[p->i - 1] != '1'
				&& !ft_isspace(p->str[p->i - 1]))
				return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static int	middle_row_spaces(t_str *p, int index)
{
	p->i = 0;
	if (p->str[p->i] && ft_isspace(p->str[p->i]))
	{
		if (check_spaces(p, index, 1))
			return (EXIT_FAILURE);
	}
	while (p->str[p->i + 1])
	{
		if (ft_isspace(p->str[p->i]))
		{
			if (check_spaces(p, index, 0))
				return (EXIT_FAILURE);
		}
		p->i++;
	}
	if (p->str[p->i] && ft_isspace(p->str[p->i]))
	{
		if (check_spaces(p, index, 2))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_spaces(char **str)
{
	int		i;
	t_str	parse;

	i = 1;
	parse.map = str;
	if (top_row_spaces(str))
		return (EXIT_FAILURE);
	while (str[i] != NULL)
	{
		parse.str = str[i];
		if (middle_row_spaces(&parse, i))
			return (EXIT_FAILURE);
		i++;
	}
	if (bot_row_spaces(str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
