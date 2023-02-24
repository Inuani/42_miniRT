/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:24:22 by egauthey          #+#    #+#             */
/*   Updated: 2023/02/24 18:30:45 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minirt.h"

void	printf_vec(t_vec vec)
{
	printf("x : %f\n", vec.x);
	printf("y : %f\n", vec.y);
	printf("z : %f\n", vec.z);
	printf("\n");
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	t_data	data;
	
	initialise_objs(&data, 5);
	init_window(&data);

	render(&data);
	mlx_hook(data.win, 17, 1L << 2, close_win, &data);
	mlx_key_hook(data.win, event_handler, &data);
	mlx_loop(data.mlx);
	return (0);
}


//TODO implement depth buffer;
