
#include "../includes/minirt.h"

int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

int	light_hit(t_ray *ray, t_data *data, t_sphere sphere)
{
	float		root2;
	t_cam		cam;
	t_light		light;

	cam = data->objs[1]->u_data.camera;
	light = data->objs[2]->u_data.light;

	t_vec vector = vec_subs(ray->point_at, light.pos);
	t_vec v = vec_subs(light.pos, sphere.center);
	vector = vec_unit(vector);
	root2 = sphere_hits(vector, v, sphere);

	t_vec light_dir = vec_subs(ray->point_at, light.pos);
	light_dir = vec_unit(light_dir);
	t_vec root_at = vec_add(light.pos, vec_scale(root2, light_dir));
	t_vec vector_l = vec_subs(root_at, light.pos);
	t_vec vector_r = vec_subs(ray->point_at, light.pos);

	if (vec_len(vector_r) - 0.01 <= vec_len(vector_l))
		return (get_angle(ray->normal, vector_l));
	return (0);
}