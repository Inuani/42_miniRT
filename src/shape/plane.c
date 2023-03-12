
#include "../../includes/minirt.h"

float inverse_map(float x)
{
	float	y;
	y = fabs(1 - x);
	return (0.0 +  ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}

float	plane_hit(t_plane *plane, t_vec ray_origine, t_vec ray_direction)
{
	float	t;
	float	numer;
	float	denom;

	numer = vec_dot(vec_subs(plane->point, ray_origine), plane->orient);
	denom = vec_dot(ray_direction, plane->orient);
	t = numer / denom;
	if (t < 0)
		return -1;
	return t;
}

void	plane_light(t_data *data, t_ray *ray, t_plane plane, t_light light)
{
	if (!light_hit_objs(data, ray->point_at, light))
		return ;
	ray->normal = plane.orient;
	ray->shiny = 5;
	phong_plane(data, ray, light, plane.colors);
}

void	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	int	i;

	i = 0;
	if (plane.flg == 2)
		plane.colors = get_texture(data, *ray, &plane);
	else if (plane.flg == 1)
		plane.colors = calculate_x_y_pcb(*ray, &plane);
	while (i < data->count.l_count)
		plane_light(data, ray, plane, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K_LIGHT, plane.colors), vec_scale(1 - K_LIGHT, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
}
