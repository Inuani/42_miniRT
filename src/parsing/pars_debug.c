#include "../../includes/minirt.h"

void	print_token(t_tok **lst)
{
	t_tok	*token;

	token = *lst;
	while (token)
	{
		printf("type: %d - str: %s\n", token->type, token->s);
		token = token->next;
	}
}
