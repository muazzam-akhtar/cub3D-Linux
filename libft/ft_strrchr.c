/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:47:49 by makhtar           #+#    #+#             */
/*   Updated: 2021/09/30 15:42:55 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	if (c == '\0')
		return ((char *)tmp);
	while (tmp >= s)
	{
		if (c == *tmp)
			return ((char *)tmp);
		tmp--;
	}
	return (0);
}
