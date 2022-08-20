/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:06:18 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/15 16:31:39 by hawadh           ###   ########.fr       */
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
	xpm->divisible = 1;
}

/**
**	Opens xpm layout images and stores them within
*	data->confg		[0] == NO, [1] == SO, [2] == WE, [3] == EA
*	data->pause		Fixed image ./imgs/pause.xpm
**/
static int	open_xpm(t_info *info, t_data *data, size_t len)
{
	size_t	i;
	int		x;
	int		y;

	i = 0;
	data->xpm = (t_xpm *)ft_calloc(4, sizeof(t_xpm));
	while (i < len)
	{
		if (i < 4)
			get_xpm_addr(info, &data->xpm[i], data->confg[i]);
		if (i > 3)
			data->confg[i] = ft_strdup(data->file[i]);
		i++;
	}
	data->gun = mlx_xpm_file_to_image(info->mlx, "./imgs/Ak47.xpm", &x, &y);
	data->pause = mlx_xpm_file_to_image(info->mlx, "./imgs/pause.xpm", &x, &y);
	if (!data->pause || !data->gun)
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
