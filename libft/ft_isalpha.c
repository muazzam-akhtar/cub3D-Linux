/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:25:20 by makhtar           #+#    #+#             */
/*   Updated: 2021/09/26 12:27:45 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	alpha;

	alpha = 1;
	if (c < 'A')
		alpha = 0;
	else if (c > 'Z' && c < 'a')
		alpha = 0;
	else if (c > 'z')
		alpha = 0;
	return (alpha);
}
