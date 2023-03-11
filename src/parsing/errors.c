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


