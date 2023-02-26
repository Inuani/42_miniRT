#include "../../includes/minirt.h"

int	is_space(int c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

void	skip_space(char *line, int *i)
{
	while(line[*i] && is_space(line[*i]))
		*i += 1;
}

float	ft_atof(const char *str)
{
	float	nb;
	float	neg;
	float	div;

	nb = 0.0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		nb = nb * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		div = 10;
		while (*str && ft_isdigit(*str))
		{
			nb = nb + (*str++ - '0') / div;
			div *= 10; 
		}
	}
	return (nb * neg);
}