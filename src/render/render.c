/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/13 14:11:02 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	render_text(t_data *data)
{
	if (data->current == 0)
		ambient_text(data);
	else if (data->current == 1)
		camera_text(data);
	else if (data->current < 2 + data->count.l_count)
		light_text(data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count)
		sphere_text(data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count
		+ data->count.pl_count)
		plane_text(data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count
		+ data->count.pl_count + data->count.cy_count)
		cylinder_text(data);
	else if (data->current < 2 + data->count.l_count + data->count.sp_count
		+ data->count.pl_count + data->count.cy_count + data->count.hy_count)
		hyperboloid_text(data);
	data->changed = 0;
}

/*
void	render(t_data *data)
{
	int		i;
	int		j;
	float	u;
	float	v;

	i = -1;
	j = HEIGHT;
	while (j-- > 0)
	{
		while (++i < WIDTH)
		{
			u = (float)(i) / (float)(WIDTH - 1);
			v = (float)(j) / (float)(HEIGHT - 1);
			t_ray ray = create_ray(&data->objs[1]->u_data.camera, data->vp, u, v);
			my_mlx_pixel_put(&(data->img), i, j, ray_color(&ray, data));
		}
		i = -1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	render_text(data);
}*/

void	render_loop(t_data *th_data, t_img *img, int ti)
{
	t_ray	ray;
	int		i;
	int		j;
	float	u;
	float	v;

	i = -1;
	j = HEIGHT - HEIGHT / THREADS * ti;
	while (j-- > HEIGHT / THREADS * (THREADS - 1 - ti))
	{
		while (++i < WIDTH)
		{
			u = (float)(i) / (float)(WIDTH - 1);
			v = (float)(j) / (float)(HEIGHT - 1);
			ray = create_ray(&th_data->objs[1]->u_data.camera,
					th_data->vp, u, v);
			my_mlx_pixel_put(img, i, j % (HEIGHT / THREADS),
				ray_color(&ray, th_data));
		}
		i = -1;
	}
}

void	*render_thr(void *dataV)
{
	int		ti;
	t_img	img;
	t_data	*data;
	t_data	th_data;

	data = (t_data *)dataV;
	pthread_mutex_lock(&data->lock);
	init_thread_data(&th_data, data);
	ti = data->thread_i;
	pthread_mutex_unlock(&data->lock);
	init_image(data, WIDTH, HEIGHT / THREADS, &img);
	render_loop(&th_data, &img, ti);
	pthread_mutex_lock(&data->lock);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0,
		HEIGHT - HEIGHT / THREADS * (ti + 1));
	data->fin++;
	pthread_mutex_unlock(&data->lock);
	free (th_data.objs);
	free_obj_list(th_data.chaos);
	free(th_data.vp);
	return (0);
}

// void	*render_thr(void *dataV)
// {
// 	int		i;
// 	int		j;
// 	float	u;
// 	float	v;
// 	t_img	img;
// 	t_data	*data  = (t_data*)dataV;
// 	t_data	th_data;
// 	pthread_mutex_lock(&data->lock);
// 	init_thread_data(&th_data, data);
// 	int ti = data->thread_i;
// 	pthread_mutex_unlock(&data->lock);
// 	i = -1;
// 	init_image(data, WIDTH, HEIGHT/THREADS, &img);
// 	j = HEIGHT - HEIGHT/THREADS * ti;
// 	while (j-- > HEIGHT/THREADS * (THREADS - 1 - ti))
// 	{
// 		while (++i < WIDTH)
// 		{
// 			u = (float)(i) / (float)(WIDTH - 1);
// 			v = (float)(j) / (float)(HEIGHT - 1);
// 			t_ray ray = create_ray(
	// &th_data.objs[1]->u_data.camera, th_data.vp, u, v);
// 			(void)ray;
// 			my_mlx_pixel_put(&img,
// i, j % (HEIGHT/THREADS), ray_color(&ray, &th_data));
// 		}
// 		i = -1;
// 	}
// 	pthread_mutex_lock(&data->lock);
// 	mlx_put_image_to_window(data->mlx,
// data->win, img.img, 0, HEIGHT - HEIGHT/THREADS * (ti + 1));
// 	data->fin++;
// 	pthread_mutex_unlock(&data->lock);
// 	free (th_data.objs);
// 	free_obj_list(th_data.chaos);
// 	free(th_data.vp);
// 	pthread_join(data->thread_id[data->thread_i], NULL);
// 	return (0);
// }