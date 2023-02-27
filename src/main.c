/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:24:22 by egauthey          #+#    #+#             */
/*   Updated: 2023/02/27 15:50:33 by lskraber         ###   ########.fr       */
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
	t_data	data;

	data.count.l_count = 0;
	data.count.sp_count = 0;
	data.count.pl_count = 0;
	data.count.cy_count = 0;

	mrt_parsing(av, &data);
	// initialise_viewport(&data);

	int i = 0;
	while(data.objs[i])
	 	print_object(*data.objs[i++]);

	// t_plane	*plane;

	// plane = (t_plane*)data.objs[4];
	// //plane->orient = vec_unit(plane->orient);
	// //printf_vec(plane->orient);
	// //printf_vec(plane->point);

	// printf("count: %i\n", data.count.sp_count);
	// init_window(&data);

	// render(&data);
	// mlx_hook(data.win, 17, 1L << 2, close_win, &data);
	// mlx_key_hook(data.win, event_handler, &data);
	// mlx_loop(data.mlx);
	return (0);
}


// TO DO implement depth buffer;
