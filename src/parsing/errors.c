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

void	free_tok(t_data *d)
{
	t_tok	*tmp;

	while (d->lst)
	{
		if (d->lst->next != NULL)
			tmp = d->lst->next;
		else
			tmp = NULL;
		free(d->lst->s);
		d->lst->s = NULL;
		free(d->lst);
		d->lst = NULL;
		d->lst = tmp;
	}
	d->lst = NULL;
}

// void	free_tok_from_end(t_tok *lst)
// {
// 	t_tok	*tmp;

// 	while (lst)
// 	{
// 		if (lst->prev != NULL)
// 			tmp = lst->prev;
// 		else
// 			tmp = NULL;
// 		// printf("%s\n", lst->s);
// 		free(lst->s);
// 		lst->s = NULL;
// 		free(lst);
// 		lst = NULL;
// 		lst = tmp;
// 	}
// }

void	free_obj_list(t_object *chaos)
{
	t_object	*tmp;

	while (chaos)
	{
		if (chaos->next != NULL)
			tmp = chaos->next;
		else
			tmp = NULL;
		free(chaos);
		chaos = NULL;
		if (tmp != NULL)
			chaos = tmp;
	}
}
