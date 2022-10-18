/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:57:12 by makhtar           #+#    #+#             */
/*   Updated: 2022/10/18 16:57:18 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_2d_len(char **str)
{
	int	count;

	count = 0;
	while (str[count] != NULL)
		count++;
	return (count);
}

int	ft_strlen_int(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
