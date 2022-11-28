/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:17:51 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/28 14:38:03 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	A function to check for fds.
*	Return value is 0 if there is no error
*	Return value is 1 if there is an error
**/
static int	xpm_store(char *str, t_info *info, const char *layout)
{
	if ((info->data->confg[0] == NULL) && !ft_strcmp(layout, "NO"))
		info->data->confg[0] = ft_strdup(str);
	else if ((info->data->confg[1] == NULL) && !ft_strcmp(layout, "SO"))
		info->data->confg[1] = ft_strdup(str);
	else if ((info->data->confg[2] == NULL) && !ft_strcmp(layout, "WE"))
		info->data->confg[2] = ft_strdup(str);
	else if ((info->data->confg[3] == NULL) && !ft_strcmp(layout, "EA"))
		info->data->confg[3] = ft_strdup(str);
	return (EXIT_SUCCESS);
}

/**
**	Checking the extension for xpm files
*	Return value is 0 for getting success
*	Return value is 1 for getting fail
**/
int	check_xpm_ext(char *str, const char *layout, t_info *info)
{
	char	*tmp;

	tmp = NULL;
	if (*str && ft_strrchr(str, '.'))
	{
		tmp = ft_strrchr(str, '.');
		if (!ft_strcmp(tmp, ".xpm"))
		{
			if (xpm_store(str, info, layout))
				return (1);
			return (0);
		}
	}
	return (1);
}

/**
**	Getting the string layout
**/
char	*get_layouts(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

/**
**	Parsing the layout for north, south, east, west with xpm files
**/
int	parse_config(char *str, const char *layout, t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, layout))
	{
		while (ft_isspace(str[i]))
			i++;
		if (!check_xpm_ext(&str[i], tmp, info))
		{
			free (tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}

/**
**	Parsing the layout for floor with xpm files
**/
int	parse_config_rgb(char *str, const char *layout, t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_layouts(str);
	if (!tmp)
		return (EXIT_FAILURE);
	while (str[i] && ft_isprint(str[i]) && !ft_isspace(str[i]))
		i++;
	if (!ft_strcmp(tmp, layout))
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str && !check_rgb(&str[i], layout, info))
		{
			free(tmp);
			return (EXIT_SUCCESS);
		}
	}
	free(tmp);
	return (EXIT_FAILURE);
}
