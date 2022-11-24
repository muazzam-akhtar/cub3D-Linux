/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:20:14 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/24 19:50:57 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	get_type(char *str)
{
	if (str == NULL)
		return (EXIT_FAILURE);
	if (!ft_strcmp(str, "NO"))
		return (1);
	else if (!ft_strcmp(str, "SO"))
		return (2);
	else if (!ft_strcmp(str, "WE"))
		return (3);
	else if (!ft_strcmp(str, "EA"))
		return (4);
	else if (!ft_strcmp(str, "C"))
		return (5);
	else if (!ft_strcmp(str, "F"))
		return (6);
	return (FALSE);
}

char	*get_type_str(int type)
{
	if (type == 1)
		return ("NO");
	else if (type == 2)
		return ("SO");
	else if (type == 3)
		return ("WE");
	else if (type == 4)
		return ("EA");
	else if (type == 5)
		return ("C");
	else if (type == 6)
		return ("F");
	return (NULL);
}

int	data_init(t_info *info, int *i, int *ret)
{
	*i = 0;
	*ret = 0;
	info->data->confg = (char **)ft_calloc(confg_count(info->data->file)
			+ 1, sizeof(char *));
	if (!info->data->confg)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_array(int *arr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (arr[i] == -1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	get_raw_layout(char *line)
{
	char		*tmp;
	int			ret;
	static int	arr[6];
	static int	i;
	static int	counter;

	tmp = NULL;
	ret = 0;
	if (!counter)
	{
		while (i < 6)
			arr[i++] = -1;
	}
	tmp = get_layouts(line);
	ret = get_type(tmp);
	free(tmp);
	arr[ret - 1] = 1;
	counter++;
	if (counter == 6)
	{
		if (check_array(arr))
			return (FALSE);
	}
	return (ret);
}
