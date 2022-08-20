/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:40:48 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/04 14:05:33 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	alpha;

	alpha = 1;
	if (c < '0')
		alpha = 0;
	else if (c > '9' && c < 'A')
		alpha = 0;
	else if (c > 'Z' && c < 'a')
		alpha = 0;
	else if (c > 'z')
		alpha = 0;
	return (alpha);
}
