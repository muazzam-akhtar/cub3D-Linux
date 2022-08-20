/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapicon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:54:14 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/12 14:58:49 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
**	Function to check character if map icon for cub3d
*	Characters can be added in the string literal:
*	N	- Player Perspective NORTH
*	S	- Player Perspective SOUTH
*	W	- Player Perspective WEST
*	E	- Player Perspective EAST
*	D	- Door
*	M	- Enemies
*	C	- Collectables
*	B	- Bullets
**/
int	ft_ismapicon(char c)
{
	if (ft_strchr("NSWEDMCB", c))
		return (TRUE);
	return (FALSE);
}
