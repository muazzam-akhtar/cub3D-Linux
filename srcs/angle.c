#include "../includes/cub.h"

double	fix_angle(double ang)
{
	if (ang < 0)
		return (ang + (2 * PI));
	else if (ang > (2 * PI))
		return (ang - (2 * PI));
	return (ang);
}