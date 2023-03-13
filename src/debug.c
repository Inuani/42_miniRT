/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	printf_vec(t_vec vec)
{
	printf("x : %f\n", vec.x);
	printf("y : %f\n", vec.y);
	printf("z : %f\n", vec.z);
	printf("\n");
}

int	print_key(int key, t_data *data)
{
	(void)data;
	printf("key : %i\n", key);
	return (0);
}

void	print_new_list(t_data *d)
{
	t_object	*tmp;
	t_object	*new_chaos;

	tmp = d->chaos;
	new_chaos = copy_obj_list_deep(tmp);
	while (new_chaos)
	{
		new_chaos = new_chaos->next;
	}
}

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
