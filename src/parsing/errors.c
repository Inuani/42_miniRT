#include "../../includes/minirt.h"

int	mrt_error(char *msg, int error)
{
	if (errno)
	{
		if (msg)
			perror(msg);
		else
			perror("Error: ");
		return (error);
	}
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
	}
	return (error);
}