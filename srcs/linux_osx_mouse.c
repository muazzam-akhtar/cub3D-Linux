/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_osx_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:23:07 by hawadh            #+#    #+#             */
/*   Updated: 2022/10/18 16:48:21 by hawadh           ###   ########.fr       */
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
		mlx_mouse_move(info->win, 960, 540);
	mlx_mouse_get_pos(info->win, &x, &y);
}
#endif