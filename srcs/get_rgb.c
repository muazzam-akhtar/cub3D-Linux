/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:44:01 by makhtar           #+#    #+#             */
/*   Updated: 2022/07/05 10:58:17 by makhtar          ###   ########.fr       */
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

/**
**	After checking the color of RGB,
*	if		success store
*	else	false
**/
static int	get_rgb(char *tmp, int *k, char *str, int i)
{
	int	ret;

	ret = ft_atoi(tmp);
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

	i = 0;
	tmp = NULL;
	k = 0;
	while (str && str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
		{
			tmp = dup_num(&str[i]);
			iterators(tmp, &i);
			fetch_rgb(tmp, info, layout);
			if (tmp && tmp[0] && ft_isdigit(tmp[0]) && get_rgb(tmp, &k, str, i))
				return (EXIT_FAILURE);
			while ((str[i] != '\0' && ft_isspace(str[i]))
				|| (str[i] != '\0' && str[i] == ','))
				i++;
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
