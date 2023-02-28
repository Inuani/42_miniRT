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

void	free_tok_from_end(t_data *d)
{
	t_tok	*tmp;

	while (d->lst)
	{
		if (d->lst->prev != NULL)
			tmp = d->lst->prev;
		else
			tmp = NULL;
		free(d->lst->s);
		d->lst->s = NULL;
		free(d->lst);
		d->lst = NULL;
		if (tmp != NULL)
			d->lst = tmp;
	}
}

