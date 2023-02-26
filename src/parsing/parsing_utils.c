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