/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:56:12 by makhtar           #+#    #+#             */
/*   Updated: 2022/09/29 14:08:32 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	fetch_rgb_ceil(char *str, t_info *info)
{
	static int	n;

	n++;
	if (n == 1)
		info->data->ceil.red = ft_atoi(str);
	else if (n == 2)
		info->data->ceil.green = ft_atoi(str);
	else if (n == 3)
		info->data->ceil.blue = ft_atoi(str);
}

void	fetch_rgb(char *str, t_info *info, const char *layout)
{
	int			col;
	static int	n;

	col = 0;
	if (!ft_strcmp(layout, "F"))
	{
		n++;
		col = ft_atoi(str);
		if (n == 1)
			info->data->floor.red = col;
		else if (n == 2)
			info->data->floor.green = col;
		else if (n == 3)
			info->data->floor.blue = col;
	}
	else if (!ft_strcmp(layout, "C"))
		fetch_rgb_ceil(str, info);
}
