/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/12 14:08:22 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	calculate_x_y_pcb(t_ray ray, t_plane *plane)
{
	int	x;
	int	y;

	if (ray.point_at.x < 0)
		ray.point_at.x -= 1;
	if (ray.point_at.y < 0)
		ray.point_at.y -= 1;
	x = ((int)ray.point_at.x % 2);
	y = ((int)ray.point_at.z % 2);
	if ((!x && !y) || (x && y))
		return ((t_vec){255, 255, 255});
	return (plane->colors);
}

// t_vec get_texture(t_data *data, t_ray ray, t_img *xpm)
// {
// 	int	x;
// 	int	y;

// 	if (ray.point_at.x < 0)
// 		ray.point_at.x = -ray.point_at.x;
// 	if (ray.point_at.z < 0)
// 		ray.point_at.z = -ray.point_at.z;
// 	x = fmod(ray.point_at.x, 1) * xpm->wdth;
// 	y = fmod(ray.point_at.z, 1) * xpm->hgt;
// 	return (decimal_to_rgb(get_color_pixel(data, x, y, xpm)));
// }

t_vec	get_texture(t_data *data, t_ray ray, t_plane *pl)
{
	int	x;
	int	y;

	(void)data;
	if (ray.point_at.x < 0)
		ray.point_at.x = -ray.point_at.x;
	if (ray.point_at.z < 0)
		ray.point_at.z = -ray.point_at.z;
	x = fmod(ray.point_at.x, 1) * pl->xpm.wdth;
	y = fmod(ray.point_at.z, 1) * pl->xpm.hgt;
	return (decimal_to_rgb(pl->pix_arr[y * pl->xpm.wdth + x]));
}

void	phong_plane(t_data *data, t_ray *ray, t_light light, t_vec obj_color)
{
	t_vec	dir;
	float	ln2;
	float	i_d;
	float	i_s;
	t_vec	diffuse_color;
	t_vec	vector;
	// t_vec	r;

	vector = vec_subs(light.pos, ray->point_at);
	vector = vec_unit(vector);
	ln2 = 2 * vec_dot(vector, ray->normal);
	// r = vec_subs(vec_scale(ln2, ray->normal), vector);
	dir = ray->direction;
	i_d = vec_dot(vector, ray->normal) * light.light_ratio;
	i_s = 0;
	if (i_d < 0)
		i_d = -i_d;
	diffuse_color = add_color(vec_scale(K_LIGHT, obj_color), vec_scale(1 - K_LIGHT, light.colors));
	data->final_color = add_colors(data->final_color, diffuse_color, i_d);
	data->final_color = add_colors(data->final_color, light.colors, i_s);
}
