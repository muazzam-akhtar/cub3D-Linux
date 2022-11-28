/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory_mngmnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:48 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/28 14:56:48 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_more(t_info *info)
{
	if (info->player)
	{
		free(info->player);
		info->player = NULL;
	}
	if (info->mlx)
	{
		free(info->mlx);
		info->mlx = NULL;
	}
}

void	free_gun(t_info *info)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(info->mlx, info->gun_var[i]);
		i++;
	}
	free(info->gun_var);
	info->gun_var = NULL;
	mlx_destroy_image(info->mlx, info->data->pause);
	info->data->pause = NULL;
	mlx_destroy_image(info->mlx, info->data->gun);
	info->data->gun = NULL;
}

/**
**	Frees 2D arrays
**/
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_config(char **str)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
	str = NULL;
}
