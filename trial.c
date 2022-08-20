#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


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

void	ft_putstr(char **str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		printf("%s\n", str[i]);
	}
}

void	free_all(char **str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}

int	ft_whitespaces(int c)
{
	if ((c >= 9 && c <= 13 ) || c == ' ')
		return (c);
	return (0);
}

int	ft_isprint(int c)
{
	int	alpha;

	alpha = 1;
	if (c < 32)
		alpha = 0;
	else if (c > 126)
		alpha = 0;
	return (alpha);
}

int	ft_isdigit(int c)
{
	int	alpha;

	alpha = 1;
	if (c < '0')
		alpha = 0;
	else if (c > '9')
		alpha = 0;
	return (alpha);
}

int	check_xpm_ext(char *str)
{
	char	*tmp;

	tmp = NULL;
	if (*str && strrchr(str, '.'))
	{
		tmp = strrchr(str, '.');
		if (!strcmp(tmp, ".xpm"))
			return (0);
	}
	return (1);
}

char	*dup_num(char *str)
{
	int	count;
	char	*tmp;
	int		i;

	count = 0;
	i = 0;
	while (str[i] && !ft_whitespaces(str[i]))
	{
		count++;
		i++;
	}
	i = i - count;
	tmp = malloc(sizeof(char) * (count + 1));
	count = 0;
	while (str[i] && !ft_whitespaces(str[i]))
	{
		tmp[count] = str[i];
		count++;
		i++;
	}
	tmp[count] = 0;
	printf("%s\n", tmp);
	return (tmp);
}

int	check_rgb(char *str)
{
	int	i;
	int	ret;
	int				count;
	char			*tmp;
	int				k;

	i = 0;
	tmp = NULL;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			count = 0;
			tmp = dup_num(&str[i]);
			while (tmp[count] && ft_isdigit(tmp[count]))
			{
				count++;
				i++;
			}
			if ((tmp[count] == 0) || (tmp[count] == ','))
			{
				i++;				
				ret = ft_atoi(tmp);
				free (tmp);
				if (ret < 0 || ret > 255)
					return (1);
				while (ft_whitespaces(str[i]))
					i++;
			}
			else
			{
				free(tmp);
				return (1);
			}
		}
		else
		{
			printf("%c", str[i]);
			return (1);
		}
	}
	return (0);
}

int	parse_north(char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (1);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_whitespaces(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	if (!strcmp(tmp, "NO"))
	{
		free (tmp);
		while (ft_whitespaces(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
			return (0);
	}
	free(tmp);
	return (1);
}

int	parse_south(char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (1);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_whitespaces(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	if (!strcmp(tmp, "SO"))
	{
		free (tmp);
		while (ft_whitespaces(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
			return (0);
	}
	free(tmp);
	return (1);
}

int	parse_west(char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (1);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_whitespaces(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	if (!strcmp(tmp, "WE"))
	{
		free (tmp);
		while (ft_whitespaces(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
			return (0);
	}
	free(tmp);
	return (1);
}

int	parse_east(char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (1);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_whitespaces(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	if (!strcmp(tmp, "EA"))
	{
		free (tmp);
		while (ft_whitespaces(str[i]))
			i++;
		if (!check_xpm_ext(&str[i]))
			return (0);
	}
	free(tmp);
	return (1);
}

int	parse_floor(char *str)
{
	int	i;
	char	*tmp;

	i = 0;
	while (str[i] && ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (i == 0)
		return (1);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (1);
	i = 0;
	while (str[i] && ft_isprint(str[i]) && !ft_whitespaces(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	if (!strcmp(tmp, "F"))
	{
		while (ft_whitespaces(str[i]))
			i++;
		if (!check_rgb(&str[i]))
		{
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	return (1);
}

int	parse_textures(char **line)
{
	int	i;

	i = 0;
	if (line[i] != NULL && parse_north(line[i++]))
		return (1);
	if (line[i] != NULL && parse_south(line[i++]))
		return (1);
	if (line[i] != NULL && parse_east(line[i++]))
		return (1);
	if (line[i] != NULL && parse_west(line[i++]))
		return (1);
	if (line[i] != NULL && parse_floor(line[i++]))
		return (1);
	// if (line[i] != NULL && parse_ceil(line[i++]))
	// 	return (1);
	return (0);
}

int main(void)
{
	char	**maps;

	maps = (char **)malloc(sizeof(char *) * 100);
	
	maps[0] = strdup("NO  beak   ./textures/GrayWalls.xpm");
	maps[1] = strdup("SO	./textures/GrayWalls.xpm");
	maps[2] = strdup("EA	./textures/GrayWalls.xpm");
	maps[3] = strdup("WE	./textures/GrayWalls.xpm");
	maps[4] = strdup("F	68,  68,  68");
	maps[5] = strdup("C	51, 204, 255");
	maps[6] = NULL;
	if (parse_textures(maps))
		printf("No\n");
	else
		printf("Yes\n");
	free_all(maps);
	return (0);
}