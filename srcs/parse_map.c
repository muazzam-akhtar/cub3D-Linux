/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:41:18 by makhtar           #+#    #+#             */
/*   Updated: 2022/08/14 21:19:08 by makhtar          ###   ########.fr       */
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
		return ('0');
	else if (c == '1')
		return ('1');
	else if (c == 'N')
		return ('N');
	else if (c == 'W')
		return ('W');
	else if (c == 'S')
		return ('S');
	else if (c == 'E')
		return ('E');
	else if (c == 'M')
		return ('M');
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
		return (1);
	else if (valid_key(c) == 'E')
		return (1);
	else if (valid_key(c) == 'S')
		return (1);
	else if (valid_key(c) == 'N')
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
static int	parse_env(char *str)
{
	static int	trigger;
	int			i;

	i = 0;
	while (str[i])
	{
		if (key_layout(str[i]))
		{
			if (trigger)
				return (EXIT_FAILURE);
			trigger = 1;
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
	int	i;

	i = index;
	if (parse_walls(str[i++]))
		return (EXIT_FAILURE);
	while (str[i + 1] != NULL)
	{
		if (parse_env(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (parse_walls(str[i]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
