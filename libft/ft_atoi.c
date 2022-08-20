/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:14:30 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/04 12:14:33 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_atoi_atoi(char *str, int sign)
{
	int			i;
	long		nbr;

	i = 0;
	nbr = 0;
	while (((unsigned char)str[i] >= '0') && ((unsigned char)str[i] <= '9'))
	{
		if ((((nbr * 10) + (str[i] - '0')) < nbr) && (sign == 1))
			return (-1);
		else if ((((nbr * 10) + (str[i] - '0')) < nbr) && (sign == -1))
			return (0);
		nbr = (nbr * 10) + ((unsigned char)str[i] - '0');
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	char	*s;
	int		sign;

	i = 0;
	s = (char *)str;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr = ft_atoi_atoi(&s[i], sign);
	nbr = nbr * sign;
	return ((int)nbr);
}
