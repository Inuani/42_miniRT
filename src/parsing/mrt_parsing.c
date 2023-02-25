// #include "../includes/minirt.h"
#include "../../includes/minirt.h"

void	parse_line(char *line)
{
	printf("%s\n", line);
}

int	mrt_parsing(char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if  (fd == -1)
		return (mrt_error(ERR_OPEN, 1));
	line = get_next_line(fd);
	parse_line(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		parse_line(line);
	}
	close(fd);
	return (0);
}
