
#include "../../includes/minirt.h"


int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

int is_inside(t_sphere sphere, t_cam camera, t_light light)
{
	float distance_to_light = vec_len(vec_subs(light.pos, sphere.center));
	float distance_to_camera = vec_len(vec_subs(camera.pos, sphere.center));

	if (distance_to_light <= sphere.radius && distance_to_camera > sphere.radius)
		return 1;
	return 0;
}

void	light_hit(t_ray *ray, t_data *data, t_sphere sphere, t_light light)
{
	if (!light_hit_objs(data, ray, ray->point_at, light))
		return ;
	if (is_inside(sphere, data->objs[1]->u_data.camera, light))
		return ;
	ray->shiny = 100;
	
	phong(data, ray, light, sphere.colors);
}

float	sphere_hits(t_vec vector, t_vec v, t_sphere sphere)
{
	float		det;

	float a = vec_dot(vector, vector); //can simplify
	float half_b = vec_dot(v, vector);
	float c = vec_dot(v, v) - (sphere.radius * sphere.radius); //can simplify
	det = half_b*half_b - a*c;

	if (det < 0)
		return (-1.0);
	float t1 = (-half_b - sqrt(det)) / a;
	float t2 = (-half_b + sqrt(det)) / a;

	if (t1 > 0.0 && (t2 < 0.0 || t1 < t2)) //change in function of camera
		return (t1);
	return (t2);
}

float it_hit_sphere(t_data *data, t_ray *ray, t_sphere sphere)
{
	int		i;
	float	ret;

	ret = 0;
	i = 0;
	ray->normal = vec_scale(1/sphere.radius, vec_subs(ray->point_at, sphere.center));
	while (i < data->count.l_count)
		light_hit(ray, data, sphere, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K, sphere.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
	return (1);
}
