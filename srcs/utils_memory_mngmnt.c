/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory_mngmnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:48 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/28 15:46:07 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Frees other allocated memory placed here
**	due to norm requirements.
*	called from free_struct_data();
**/
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

/**
**	Free and destroy gun images.
**/
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

/**
**	For freeing config
*
*	while (i < 6)	Number of elements in config is 6.
*
*	For any errors some indexes will not be filled and hence
*	hardcoded value of 6 is taken.
*
**/
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
