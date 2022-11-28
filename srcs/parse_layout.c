/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:19:03 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/28 12:00:36 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Counts number of lines of config
**/
size_t	confg_count(char **file)
{
	size_t	count;

	count = 0;
	while (file[count] && !check_if_map(file[count]))
		count++;
	return (count);
}

/**
**	Stores config of file in data->confg
*	Confg is first line before map
*	Which includes N, S, E, W and C, F
**/
static int	store_map(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	ptr_len;

	j = 0;
	len = confg_count(data->file);
	ptr_len = ft_ptrptrlen(data->file) - len;
	data->map = (char **)ft_calloc(ptr_len + 1, sizeof(char *));
	if (!data->map)
		return (EXIT_FAILURE);
	i = len;
	while (data->file[i])
		data->map[j++] = ft_strdup(data->file[i++]);
	return (EXIT_SUCCESS);
}

/**
**	With the order, parsing all layouts
**/
static int	parse_layout(char **line, int *index, t_info *info)
{
	int		i;
	int		ret;

	if (data_init(info, &i, &ret))
		return (EXIT_FAILURE);
	while (i < 6 && line[i] != NULL)
	{
		ret = get_raw_layout(line[i]);
		if (ret == FALSE)
			return (EXIT_FAILURE);
		else if (ret == 5 || ret == 6)
		{
			if (parse_config_rgb(line[i++], get_type_str(ret), info))
				return (EXIT_FAILURE);
		}
		else
		{
			if (parse_config(line[i++], get_type_str(ret), info))
				return (EXIT_FAILURE);
		}
	}
	*index = i;
	return (EXIT_SUCCESS);
}

/**
**	Calls parser for maps and config
**/
int	parse_arg(char **maps, t_info *info)
{
	int	index;

	index = 0;
	if (parse_layout(maps, &index, info))
		err_return(6, info);
	if (parse_map(maps, index))
		err_return(3, info);
	if (store_map(info->data))
		return (EXIT_FAILURE);
	printf("\n");
	printf("NO	:	%s\n", info->data->confg[0]);
	printf("SO	:	%s\n", info->data->confg[1]);
	printf("WE	:	%s\n", info->data->confg[2]);
	printf("EA	:	%s\n", info->data->confg[3]);
	printf("\nF	:	R: %d,	G: %d,	B: %d\n",
		info->data->floor.red, info->data->floor.green,
		info->data->floor.blue);
	printf("C	:	R: %d,	G: %d,	B: %d\n", info->data->ceil.red,
		info->data->ceil.green, info->data->ceil.blue);
	return (EXIT_SUCCESS);
}

/**
**	Called from check_map_lines(); in utils_file_ext.c
*
*	Confirms if input is a map configuration element
*
**/
int	check_map_config_lines(char *input)
{
	if (!ft_strncmp(input, "F", 1) || !ft_strncmp(input, "C", 1))
		return (EXIT_SUCCESS);
	if (!ft_strncmp(input, "NO", 2) || !ft_strncmp(input, "SO", 2))
		return (EXIT_SUCCESS);
	if (!ft_strncmp(input, "EA", 2) || !ft_strncmp(input, "WE", 2))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
