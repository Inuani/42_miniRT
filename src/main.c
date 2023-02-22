/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:24:22 by egauthey          #+#    #+#             */
/*   Updated: 2023/02/22 15:19:01 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minirt.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	t_data	data;

	init_window(&data);
	
	mlx_hook(data.win, 17, 1L << 2, close_win, &data);
	mlx_key_hook(data.win, event_handler, &data);
	mlx_loop(data.mlx);
	return (0);
}

