/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:02:35 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/28 15:46:57 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	free_xpm(t_info *info, t_data *data)
{
	int	i;

	i = 0;
	while (data->xpm[i].img)
	{
		if (data->xpm[i].addr)
			data->xpm[i].addr = NULL;
		mlx_destroy_image(info->mlx, data->xpm[i].img);
		i++;
	}
	free(data->xpm);
}

static void	free_struct_mini(t_mini *mini)
{
	if (mini->addr)
		mini->addr = NULL;
	if (mini)
	{
		free(mini);
		mini = NULL;
	}
}

static void	free_struct_img(t_img *img)
{
	if (img->addr)
		img->addr = NULL;
	if (img)
		img = NULL;
}

static void	free_struct_data(t_info *info, t_data *data)
{
	if (data->xpm)
		free_xpm(info, data);
	if (data->map)
	{
		free_split(data->map);
		data->map = NULL;
	}
	if (data->confg)
	{
		free_config(data->confg);
		data->confg = NULL;
	}
	if (data->file)
	{
		free_split(data->file);
		data->file = NULL;
	}
}

/**
**	Frees all the Data
**/
void	free_data(t_info *info)
{
	if (info->data)
		free_struct_data(info, info->data);
	if (info->image)
		free_struct_img(info->image);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mini)
		free_struct_mini(info->mini);
	if (info->mouse)
	{
		free(info->mouse);
		info->mouse = NULL;
	}
	if (info->gun_var)
		free_gun(info);
	if (info->doors)
		free(info->doors);
	free_more(info);
}
