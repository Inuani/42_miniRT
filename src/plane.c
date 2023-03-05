
#include "../includes/minirt.h"


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
	if (!light_hit_objs(data, ray, ray->point_at, light))
		return ;

	ray->normal = plane.orient;
	ray->shiny = 25;
	phong(data, ray, light, plane.colors);
}


void	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	int		i;

	i = 0;

	while (i < data->count.l_count)
		plane_light(data, ray, plane, data->objs[2 + i++]->u_data.light);

	t_vec ambient_color = add_color(vec_scale(K, plane.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
}
