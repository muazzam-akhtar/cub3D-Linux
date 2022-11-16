/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_osx_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:23:07 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/16 18:45:16 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#ifdef LINUX

void	linux_osx_mouse(t_info *info, int x, int y, int status)
{
	if (status == 1)
		mlx_mouse_move(info->mlx, info->win, 960, 540);
	mlx_mouse_get_pos(info->mlx, info->win, &x, &y);
}
#endif
#ifndef LINUX

void	linux_osx_mouse(t_info *info, int x, int y, int status)
{
	if (status == 1)
		mlx_mouse_move(info->win, 480, 360);
	mlx_mouse_get_pos(info->win, &x, &y);
}
#endif