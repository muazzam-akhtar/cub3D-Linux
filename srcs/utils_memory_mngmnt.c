/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory_mngmnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:48 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/13 13:46:57 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Frees 2D arrays
**/
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i])
			free(str[i++]);
	if (str)
		free(str);
}
