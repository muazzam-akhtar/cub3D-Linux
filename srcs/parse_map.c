/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:41:18 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/24 19:29:35 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Parsing for walls to check for top and bottom of the map
**/
static int	parse_walls(char *str)
{
	int	i;

	i = 0;
	if (str && (*str))
	{
		while (str[i])
		{
			if (valid_key(str[i]) == '1' || ft_isspace(str[i]))
				i++;
			else
				return (EXIT_FAILURE);
		}
		if (str[--i] != '1')
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
**	In map we need an indictaion for setting the layout and getting
**	the starting position of the player, We need only one part of
**	the layout, if there is more then we're throwing an error.
**/
static int	key_layout(int c)
{
	if (valid_key(c) == 'W')
		return (TRUE);
	else if (valid_key(c) == 'E')
		return (TRUE);
	else if (valid_key(c) == 'S')
		return (TRUE);
	else if (valid_key(c) == 'N')
		return (TRUE);
	return (FALSE);
}

static int	parse_zero(char **map, char *str, int index, int i)
{
	(void)str;
	if (i == 0 || index == 0)
		return (EXIT_FAILURE);
	if ((index - 1) <= 0 || i >= ft_strlen_int(map[index - 1]))
		return (EXIT_FAILURE);
	if ((index + 1) >= get_2d_len(map) || i >= ft_strlen_int(map[index + 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
**	Parsing the middle part of the map and taking everything into the
**	account
**	Valid Keys:
*	0: Free space
*	1: Walls
*	W: West Navigator
*	N: North Navigator 
*	S: South Navigator
*	E: East Navigator
**/
static int	parse_env(char *str, int *trigger, char **map, int index)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (key_layout(str[i]))
		{
			if (*trigger)
				return (EXIT_FAILURE);
			*trigger = 1;
		}
		else if (!valid_key(str[i]) && !ft_isspace(str[i]))
			return (EXIT_FAILURE);
		else if (valid_key(str[i]) == '0')
			if (parse_zero(map, str, index, i))
				return (EXIT_FAILURE);
		i++;
	}
	if ((str[i - 2] == '1' && str[i - 1] == 10)
		|| str[i - 1] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/**
**	The root function of parsing of the map
**/
int	parse_map(char **str, int index)
{
	int			i;
	static int	trigger;

	i = index;
	if (parse_walls(str[i++]))
		return (EXIT_FAILURE);
	if (str[i] == NULL)
		return (EXIT_FAILURE);
	while (str[i + 1] != NULL)
	{
		if (parse_env(str[i], &trigger, str, i))
			return (EXIT_FAILURE);
		i++;
	}
	if (!trigger || parse_walls(str[i]) || parse_spaces(&str[index]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
