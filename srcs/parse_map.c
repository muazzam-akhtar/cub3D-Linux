/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:41:18 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/18 17:05:02 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Getting valid keys for the map
*!	LINE #33 -> LINE #34 ADDED BY HA
**/
static int	valid_key(int c)
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
	else if (c == 'M')
		return (c);
	else if (c == 'D')
		return (c);
	else if (c == 'U')
		return (c);
	else if (c == 'V')
		return (c);
	return (FALSE);
}

/**
**	Parsing for walls to check for top and bottom of the map
**/
static int	parse_walls(char *str)
{
	int	i;

	i = 0;
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
static int	parse_env(char *str, int *trigger)
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
		if (parse_env(str[i], &trigger))
			return (EXIT_FAILURE);
		i++;
	}
	if (!trigger || parse_walls(str[i]) || parse_spaces(&str[index]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
