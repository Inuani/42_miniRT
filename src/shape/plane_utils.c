/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lskraber <lskraber@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:05:42 by lskraber          #+#    #+#             */
/*   Updated: 2023/03/13 13:53:02 by lskraber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec	calculate_x_y_pcb(t_ray ray, t_plane *plane)
{
	int	x;
	int	y;

	if (!plane->orient.x && !plane->orient.y)
		ray.point_at.z = ray.point_at.y;
	if (ray.point_at.x < 0)
		ray.point_at.x *= -1;
	if (ray.point_at.z < 0)
		ray.point_at.z *= -1;
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
	if (!pl->orient.x && !pl->orient.y)
		ray.point_at.z = ray.point_at.y;
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
	float	i_d;
	t_vec	vector;
	t_vec	diffuse_color;

	vector = vec_subs(ray->point_at, light.pos);
	vector = vec_unit(vector);
	i_d = vec_dot(vector, ray->normal) * light.light_ratio;
	if (i_d < 0)
		i_d = -i_d;
	diffuse_color = add_color(vec_scale(K_LIGHT, obj_color),
			vec_scale(1 - K_LIGHT, light.colors));
	data->final_color = add_colors(data->final_color, diffuse_color, i_d);
}
