/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:42:11 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/18 19:14:33 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Remove character c from string s1
 * FREE REQ
 **/

char	*ft_strrmc(char *s1, char c)
{
	char	*tmp;
	char	*ptr;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	ptr = ft_strchr(s1, c);
	i = 0;
	while (*s1)
	{
		while (ptr)
		{
			while (ptr - s1)
				tmp[i++] = *(s1++);
			ptr = ft_strchr(++s1, c);
		}
		tmp[i++] = *(s1++);
	}
	tmp[i] = 0x00;
	return (tmp);
}
