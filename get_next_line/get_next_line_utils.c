/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawadh <hawadh@Student.42Abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:10:05 by hawadh            #+#    #+#             */
/*   Updated: 2022/07/01 10:06:00 by hawadh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dup_to_new_line(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	while (s1[i] != '\n' && s1[i] != 0)
		i++;
	if (s1[i] == '\n')
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	if (!(dup))
		return (NULL);
	while (s1[i] != '\n' && s1[i] != 0)
	{
		dup[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*get_strjoin(char *s1, char *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	out = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[i] != 0)
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		out[i++] = s2[j++];
	let_it_go(&s1);
	out[i] = 0;
	return (out);
}
