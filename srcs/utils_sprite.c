/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:02:45 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/14 18:34:32 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_sprite(int c)
{
	if (c == 'C')
		return (TRUE);
	else if (c == 'D')
		return (TRUE);
	return (FALSE);
}

void	free_spr(t_sprite *spr)
{
	while (spr && spr->next != NULL)
	{
		spr = spr->next;
	}
	while (spr && spr->prev != NULL)
	{
		free(spr);
		spr = spr->prev;
		spr = NULL;
	}
	free(spr);
	spr = NULL;
}
