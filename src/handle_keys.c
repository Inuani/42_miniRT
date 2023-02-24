/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/02/24 12:56:52 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	event_handler(int key, t_data *data)
{
	(void) data;
	if (key == 53)
		exit(0);
	return (0);
}