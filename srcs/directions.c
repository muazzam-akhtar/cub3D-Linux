/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:30:47 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/05 21:53:12 by makhtar          ###   ########.fr       */
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

int	wall_hit_direction(t_ray *ray, double old_x, double old_y, t_info *inf)
{
	double		diff_x;
	double		diff_y;
	static int	timer;

	(void)inf;
	diff_x = ray->x - old_x;
	diff_y = ray->y - old_y;
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
	// if (timer  0)
	// {
		printf("Old x: %f, Old y: %f, NewX: %f, NewY: %f\n", old_x, old_y, ray->x, ray->y);
		printf("Diff_X: %f, Diff_Y: %f\n", diff_x, diff_y);
		printf("Map[Ox][Oy]: %c\n", inf->data->map[(int)old_y][(int)old_x]);
		printf("Map[Ox][Ny]: %c\n", inf->data->map[(int)ray->y][(int)old_x]);
		printf("Map[Nx][Oy]: %c\n", inf->data->map[(int)old_y][(int)ray->x]);
		// timer = 0;
	// }
	if (timer == 1920)
	{
		timer = 0;
		print_map(inf->data->map);
	}
	timer++;
	return (EXIT_SUCCESS);
}
