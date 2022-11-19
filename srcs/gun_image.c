/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:43:00 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/19 19:17:39 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	gun_image(t_info *inf)
{
	if (inf->fire == 0)
		mlx_put_image_to_window(inf->mlx, inf->win,
			inf->data->gun, (WIDTH / 2) - 75, (HEIGHT / 2));
	else
		mlx_put_image_to_window(inf->mlx, inf->win,
			inf->data->gun_anim, (WIDTH / 2) - 75, (HEIGHT / 2));
}

void	printing_image(t_info *info)
{
	static int	index;

	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
	if (info->fire == 0)
		mlx_put_image_to_window(info->mlx, info->win,
			info->data->gun, (WIDTH / 2) - 75, (HEIGHT / 2));
	else
	{
		info->data->gun_anim = info->gun_var[index];
		mlx_put_image_to_window(info->mlx, info->win,
			info->data->gun_anim, (WIDTH / 2) - 75, (HEIGHT / 2));
		index++;
		if (index > 4)
			index = 0;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->mini_map, 30, 30);
}
