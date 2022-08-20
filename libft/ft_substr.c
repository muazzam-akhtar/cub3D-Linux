/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:01:42 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/07 12:02:08 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (s)
	{
		if (ft_strlen(s) <= start)
			return (ft_strdup(""));
		if (len >= ft_strlen(s))
			len = ft_strlen(s);
		substr = malloc(sizeof(char) * (len + 1));
		if (!substr)
			return (NULL);
		i = 0;
		while ((i < len) && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
