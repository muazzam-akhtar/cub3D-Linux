/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:44:01 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/24 19:19:23 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Getting the int values in a string so it can execute atoi
**/
static char	*dup_num(char *str)
{
	int		count;
	char	*tmp;
	int		i;

	count = 0;
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		count++;
		i++;
	}
	i = i - count;
	tmp = malloc(sizeof(char) * (count + 1));
	count = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		tmp[count] = str[i];
		count++;
		i++;
	}
	tmp[count] = 0;
	return (tmp);
}

static int	parse_num(char *str)
{
	int		ret;
	char	*dup;
	int		i;

	dup = ft_strdup(str);
	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	dup[i] = 0;
	ret = ft_atoi(dup);
	if (calc_digits(ret) == ft_strlen_int(dup))
	{
		free(dup);
		return (EXIT_SUCCESS);
	}
	free(dup);
	return (EXIT_FAILURE);
}

/**
**	After checking the color of RGB,
*	if		success store
*	else	false
**/
static int	get_rgb(char *tmp, int *k, char *str, int i)
{
	int		ret;

	ret = ft_atoi(tmp);
	if (parse_num(tmp))
	{
		free (tmp);
		return (EXIT_FAILURE);
	}
	free (tmp);
	(*k)++;
	if (ret < 0 || ret > 255)
		return (TRUE);
	if (*k > 3 || (*k == 3 && str[i] == ','))
		return (TRUE);
	return (FALSE);
}

/**
**	Iterating through the index of numbers
**/
static void	iterators(char *tmp, int *i)
{
	int	count;

	count = 0;
	while (tmp[count] && ft_isdigit(tmp[count]))
	{
		count++;
		(*i)++;
	}
}

/**
**	Parse function of RGB colors
**/
int	check_rgb(char *str, const char *layout, t_info *info)
{
	int				i;
	char			*tmp;
	int				k;
	int				count;

	init_num(&i, &tmp, &k, &count);
	while (str && str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
		{
			tmp = dup_num(&str[i]);
			iterators(tmp, &i);
			fetch_rgb(tmp, info, layout);
			if (tmp && tmp[0] && ft_isdigit(tmp[0]) && get_rgb(tmp, &k, str, i))
				return (EXIT_FAILURE);
			if (str[i] != '\0' && str[i] == ',')
				i++;
			count++;
		}
		else
			return (EXIT_FAILURE);
	}
	if (count == 3)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
