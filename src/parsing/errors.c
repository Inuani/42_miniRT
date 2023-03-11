#include "../../includes/minirt.h"

void	exit_error(char *msg, int error)
{
	if (errno)
	{
		if (msg)
			perror(msg);
		else
			perror("Error: ");
		exit(error);
	}
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	//free
	exit(error);
}


