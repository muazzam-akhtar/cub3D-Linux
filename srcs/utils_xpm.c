/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:06:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/28 12:10:32 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Extracting xpm image addresses
**/
static void	get_xpm_addr(t_info *info, t_xpm *xpm, char *xpm_str)
{
	xpm->img = mlx_xpm_file_to_image(info->mlx, xpm_str, &xpm->wi, &xpm->hi);
	if (!xpm->img)
		err_return(5, info);
	xpm->addr = mlx_get_data_addr(xpm->img, &xpm->bitspix,
			&xpm->len, &xpm->end);
	if (!xpm->addr)
		err_return(4, info);
	xpm->addr = xpm->addr + (xpm->len * (xpm->bitspix / 8));
}

/**
**	Initialises all bonus xpm files
*
*	1. Gun 				"Ak47.xpm"
*	2. Pause 			"pause.xpm"
*	3. Gun Animation	"Ak47_*.xpm" (Ak47_1.xpm Ak47_2.xpm etc;)
*	4. Door				"door.xpm"
*
**/
static int	init_bonus_xpm(t_info *info, t_data *data)
{
	int		x;
	int		y;

	data->gun = mlx_xpm_file_to_image(info->mlx, "./imgs/Ak47.xpm", &x, &y);
	data->pause = mlx_xpm_file_to_image(info->mlx, "./imgs/pause.xpm", &x, &y);
	info->gun_var = (void **)ft_calloc(6, sizeof(void *));
	info->gun_var[0] = mlx_xpm_file_to_image(info->mlx,
			"./imgs/Fired Ak47_1.xpm", &x, &y);
	info->gun_var[1] = mlx_xpm_file_to_image(info->mlx,
			"./imgs/Fired Ak47_2.xpm", &x, &y);
	info->gun_var[2] = mlx_xpm_file_to_image(info->mlx,
			"./imgs/Fired Ak47_3.xpm", &x, &y);
	info->gun_var[3] = mlx_xpm_file_to_image(info->mlx,
			"./imgs/Fired Ak47_4.xpm", &x, &y);
	info->gun_var[4] = mlx_xpm_file_to_image(info->mlx,
			"./imgs/Fired Ak47_5.xpm", &x, &y);
	info->gun_var[5] = NULL;
	data->gun_anim = info->gun_var[0];
	get_xpm_addr(info, &data->xpm[DO], "./imgs/door.xpm");
	if (!data->pause || !data->gun || !data->gun_anim || !info->gun_var)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
**	Opens xpm layout images and stores them within
*	data->confg			[0] == NO, [1] == SO, [2] == WE, [3] == EA
*	data->pause			Fixed image ./imgs/pause.xpm
*	init_bonus_xpm()	Loads additional xpm images for bonus
**/
static int	open_xpm(t_info *info, t_data *data, size_t len)
{
	size_t	i;

	i = 0;
	data->xpm = (t_xpm *)ft_calloc((4 + NUM_SPRITES) + 1, sizeof(t_xpm));
	while (i < len)
	{
		if (i < 4)
			get_xpm_addr(info, &data->xpm[i], data->confg[i]);
		if (i > 3)
			data->confg[i] = ft_strdup(data->file[i]);
		i++;
	}
	if (init_bonus_xpm(info, data))
		err_return(5, info);
	return (EXIT_SUCCESS);
}

/**
**	Inits data->config and calls open_xpm();
**	to open and store xpm images
*	TODO:	Load all xpm images through this function
**/
int	init_xpm(t_info *info, t_data *data)
{
	if (open_xpm(info, data, confg_count(data->file)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
