
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

int	plane_light(t_ray *ray, t_data *data, t_plane plane)
{
	t_light		light;

	light = data->objs[2]->u_data.light;
	t_vec dir = vec_subs(ray->point_at, light.pos);
	//if (vec_dot(dir, ray->normal) < 0);
	dir = vec_unit(dir); //kinda useless, maybe faster?
	float value = get_angle(plane.orient, dir); //maybe take less values so program runs faster.
	return value;
}


int	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	float	root;
	t_cam	cam;

	cam = data->objs[1]->u_data.camera;
	plane.orient = vec_unit(plane.orient);
	root = plane_hit(&plane, cam.pos, ray->direction);
	//ray->point_at = (t_vec){cam.pos.x, cam.pos.y, cam.pos.z}; //useless

	if (root < 0)
		return -1;

	ray->point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
	
	if (!light_hit_objs(data, ray, ray->point_at))
		return (0);
	float value = plane_light(ray, data, plane);
	//if (value)
	return (value);//can optimize
	//return 0;
}
