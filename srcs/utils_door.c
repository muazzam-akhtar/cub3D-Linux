/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:02:39 by makhtar           #+#    #+#             */
/*   Updated: 2022/11/16 17:21:06 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	door_check(t_info *inf, int y, int x)
{
	if ((inf->data->map[y][x - 1] == '1') && (inf->data->map[y][x + 1] == '1'))
		return (EXIT_SUCCESS);
	else if ((inf->data->map[y + 1][x] == '1')
		&& (inf->data->map[y - 1][x] == '1'))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static void	place_vals_doors(t_door *doors, int x, int y, int i)
{
	doors->m_x = x;
	doors->m_y = y;
	doors->open = 0;
	doors->dist = 0;
	doors->height = 0;
	doors->y_pos = 0;
	doors->x_pos = 0;
	doors->i = i;
}

void	print_door_info(t_info *inf)
{
	int	i;

	i = 0;
	while (i < inf->n_doors)
	{
		printf("Index: %d -> X: %d, Y: %d\n", inf->doors[i].i,
			inf->doors[i].m_x, inf->doors[i].m_y);
		i++;
	}
}

static int	allocate_doors(t_info *info, int count)
{
	int	i;
	int	x;
	int	y;

	info->n_doors = count;
	if (count == 0)
		return (EXIT_SUCCESS);
	info->doors = (t_door *)malloc(sizeof(t_door) * (count + 1));
	i = 0;
	y = 0;
	while (info->data->map[y] != NULL)
	{
		x = 0;
		while (info->data->map[y][x])
		{
			if (info->data->map[y][x] == 'D')
			{
				place_vals_doors(&info->doors[i], x, y, i);
				i++;
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	parse_doors(t_info *inf)
{
	static int	y;
	int			x;
	static int	count;

	y = 0;
	while (inf->data->map[y] != NULL)
	{
		x = 0;
		while (inf->data->map[y][x])
		{
			if (inf->data->map[y][x] == 'D')
			{
				if (x == 0 || (x + 1) == (int)ft_strlen(inf->data->map[y])
					|| y == 0 || (y + 1) == (int)ft_ptrptrlen(inf->data->map))
					err_return(3, inf);
				if (door_check(inf, y, x))
					err_return(3, inf);
				count++;
			}
			x++;
		}
		y++;
	}
	allocate_doors(inf, count);
	return (EXIT_SUCCESS);
}
