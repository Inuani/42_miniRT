/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:32:41 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/06 14:22:31 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	close_win(void)
{
	exit(0);
	return (0);
}

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "MiniRT");
	//data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	//data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
	//		&data->img.line_length, &data->img.endian);
}

void	init_image(t_data *data, int width, int height, t_img *img)
{
	img->img = mlx_new_image(data->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}