
#include "../../includes/minirt.h"

float inverse_map(float x)
{
	float	y;
	y = fabs(1 - x);
	return (0.0 +  ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}


void	phong_plane(t_data *data, t_ray *ray, t_light light, t_vec obj_color)
{
	t_vec	R;
	t_vec	dir;
	float	ln2;
	float	i_d;
	float	i_s;

	t_vec vector = vec_subs(light.pos, ray->point_at);
	vector = vec_unit(vector);
	ln2 = 2 * vec_dot(vector, ray->normal);
	R = vec_subs(vec_scale(ln2, ray->normal), vector);
	dir = ray->direction;
	i_d = vec_dot(vector, ray->normal) * light.light_ratio;
	i_s = 0;
	if (i_d < 0)
		i_d = -i_d;
	
	t_vec diffuse_color = add_color(vec_scale(K_LIGHT, obj_color), vec_scale(1 - K_LIGHT, light.colors));
	data->final_color = add_colors(data->final_color, diffuse_color, i_d);
	data->final_color = add_colors(data->final_color, light.colors, i_s);
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

// void get_texture(t_data *data, t_ray *ray, t_plane *plane)
// {
// 	int w;
// 	int h;
// 	int	x;
// 	int	y;

// 	getcolorofpixel(data, &w, &h);
// 	x = ((int)ray->point_at.x % 2) / w;
// 	y = ((int)ray->point_at.z % 2) / h;
// 	plane->colors = decimalToRGB(get_color_pixel(data, &w, &h, plane));
// }

t_vec calculate_x_y_pcb(t_ray ray, t_plane *plane)
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
		return ((t_vec) {255, 255, 255});
	return (plane->colors);
}

void	plane_light(t_data *data, t_ray *ray, t_plane plane, t_light light)
{
	if (!light_hit_objs(data, ray->point_at, light))
		return ;

	//get_texture(data, ray, &plane);
	ray->normal = plane.orient;
	ray->shiny = 5;
	phong_plane(data, ray, light, plane.colors);
}


void	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	int		i;

	i = 0;

	plane.colors = calculate_x_y_pcb(*ray, &plane);
	while (i < data->count.l_count)
		plane_light(data, ray, plane, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K_LIGHT, plane.colors), vec_scale(1 - K_LIGHT, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
}
