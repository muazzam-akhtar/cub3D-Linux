/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:30:47 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/13 18:30:22 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	print_map(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		printf("%s\n", str[i]);
		i++;
	}
}

/**
**	Fetches the side of the wall when hitted with the ray
**/
int	wall_hit_direction(t_ray *ray, double old_x, double old_y, t_info *inf)
{
	// print_map(inf->data->map);
	if (inf->data->map[(int)ray->y][(int)old_x] == '1')
	{
		if (old_y < ray->y)
			return (2);
		else if (old_y > ray->y)
			return (1);
		else if (old_y == ray->y)
			return (5);
	}
	else if (inf->data->map[(int)old_y][(int)ray->x] == '1')
	{
		if (old_x < ray->x)
			return (4);
		else if (old_x > ray->x)
			return (3);
		else if (old_x == ray->x)
			return (5);
	}
	return (FALSE);
}
