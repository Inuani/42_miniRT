/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:24:22 by egauthey          #+#    #+#             */
/*   Updated: 2023/03/11 13:59:46 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit_err(ERR_USAGE, 0);
	data.changed = 1;
	data.current = 0;
	mrt_parsing(av, &data);
	create_thread(&data);
	mlx_hook(data.win, 17, 1L << 2, close_win, &data);
	mlx_key_hook(data.win, event_handler, &data);
	mlx_loop(data.mlx);
	return (0);
}

	// (void)ac;
	// t_data	data;

	// data.changed = 1;
	// data.current = 0;
	// mrt_parsing(av, &data);
	// // int i = 0;
	// // while(data.objs[i])
	// //  	print_object(*data.objs[i++]);

	// //render(&data);
	// create_thread(&data);
	// mlx_hook(data.win, 17, 1L << 2, close_win, &data);
	// mlx_key_hook(data.win, event_handler, &data);
	// //mlx_key_hook(data.win, print_key, &data);
	// mlx_loop(data.mlx);
	// return (0);
