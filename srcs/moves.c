/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:49:11 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/03 18:51:49 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Main Raycasting
*	Handle Moves- W, S, A, D
*	Handle Rotations- Left and Right
**/
void	moves(int hook_num, t_info *inf)
{
	handle_wall_collision(inf);
	if (hook_num == W)
		move_frwrd(inf);
	else if (hook_num == S)
		move_back(inf);
	else if (hook_num == A)
		move_left(inf);
	else if (hook_num == D)
		move_right(inf);
	else if (hook_num == ARROW_L || hook_num == ARROW_R)
		rotation(hook_num, inf);
	handle_wall_collision(inf);
	init_rays(inf);
}
