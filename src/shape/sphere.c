/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/12 14:08:22 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	is_inside(t_sphere sphere, t_cam camera, t_light light)
{
	float	distance_to_light;
	float	distance_to_camera;

	distance_to_light = vec_len(vec_subs(light.pos, sphere.center));
	distance_to_camera = vec_len(vec_subs(camera.pos, sphere.center));
	if (distance_to_light <= sphere.radius
		&& distance_to_camera > sphere.radius)
		return (1);
	return (0);
}

void	light_hit(t_ray *ray, t_data *data, t_sphere *sphere, t_light light)
{
	if (!light_hit_objs(data, ray->point_at, light))
		return ;
	if (is_inside(*sphere, data->objs[1]->u_data.camera, light))
		return ;
	ray->shiny = 100;
	phong(data, ray, light, sphere->colors);
}

float	sphere_hits(t_vec vector, t_vec v, t_sphere sphere)
{
	float	det;
	float	a;
	float	half_b;
	float	c;
	float	t[2];

	a = vec_dot(vector, vector);
	half_b = vec_dot(v, vector);
	c = vec_dot(v, v) - (sphere.radius * sphere.radius);
	det = half_b * half_b - a * c;
	if (det < 0)
		return (-1.0);
	t[0] = (-half_b - sqrt(det)) / a;
	t[1] = (-half_b + sqrt(det)) / a;
	if (t[0] > 0.0 && (t[1] < 0.0 || t[0] < t[1]))
		return (t[0]);
	return (t[1]);
}

float	it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere)
{
	int		i;
	float	ret;
	t_vec	ambient_color;

	ray->normal = vec_scale(1 / sphere.radius,
			vec_subs(ray->point_at, sphere.center));
	if (sphere.flg == 2)
		sphere.colors = get_sp_xpm_color(ray, &sphere);
	else if (sphere.flg == 1)
		sphere.colors = calculate_x_y_scb(ray, &sphere);
	ret = 0;
	i = 0;
	while (i < data->count.l_count)
		light_hit(ray, data, &sphere, data->objs[2 + i++]->u_data.light);
	ambient_color = add_color(vec_scale(K_LIGHT, sphere.colors),
			vec_scale(1 - K_LIGHT, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color,
			ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return (1);
}

	// t_vec	normal_map_color;
		// normal_map_color = get_sp_xpm_color(data, ray, &sphere.n_map);
		// sphere.colors = vec_add(get_sp_xpm_color(data,
		// 	ray, &sphere.xpm), normal_map_color);

		// sphere.colors = add_colors(get_sp_xpm_color(data,
		// 	ray, &sphere.xpm), normal_map_color, 0.05);
