
#include "../includes/minirt.h"



int	plane_hit(t_data *data, t_ray *ray, t_plane *plane)
{
	float	t;
	float	numer;
	float	denom;
	t_cam	cam;

	cam = data->objs[1]->u_data.camera;
	numer = vec_dot(vec_subs(plane->point, cam.pos), plane->orient);
	denom = vec_dot(ray->direction, plane->orient);

	t = (float)numer / (float)denom;

	if (t < 0)
		return -1;
	else
		return 1;
}
/*
int	get_angle(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}

int	plane_light(t_ray *ray, t_data *data, t_sphere sphere)
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
}*/

int	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	float	root;

	plane.orient = vec_unit(plane.orient);
	root = plane_hit(data, ray, &plane);
	ray->point_at = (t_vec){0, 0, 0};
	if (root < 0)
		return -1;
	ray->point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));

	return 0;
}
