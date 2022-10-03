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