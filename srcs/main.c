/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:29 by hawadh            #+#    #+#             */
/*   Updated: 2022/11/28 14:19:24 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/**
**	Init's MLX and other variables
**/
static int	init(t_info *info)
{
	if (parse_doors(info))
		return (EXIT_FAILURE);
	info->mlx = mlx_init();
	if (!info->mlx)
		return (EXIT_FAILURE);
	if (init_window(info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;

	ft_memset(&info, 0, sizeof(t_info));
	ft_memset(&data, 0, sizeof(t_data));
	info.data = &data;
	if (argc == 2)
	{
		check_map(&info, argv[1]);
		if (init(&info))
		{
			free_data(&info);
			return (EXIT_FAILURE);
		}
	}
	else
		err_return(2, &info);
	free_data(&info);
	return (EXIT_SUCCESS);
}
