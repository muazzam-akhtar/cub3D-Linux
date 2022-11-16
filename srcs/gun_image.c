/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:43:00 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/16 18:03:51 by makhtar          ###   ########.fr       */
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
