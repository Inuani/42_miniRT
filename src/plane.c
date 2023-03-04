
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

int	plane_light(t_ray *ray, t_plane plane, t_light light)
{
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
	int		i;
	float	value;
	float	v_tmp;

	i = 0;
	value = 90.0;
	cam = data->objs[1]->u_data.camera;
	plane.orient = vec_unit(plane.orient);
	root = plane_hit(&plane, cam.pos, ray->direction);

	if (root < 0)
		return -1;

	ray->point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
	
	if (!light_hit_objs(data, ray, ray->point_at))
		return (0);
	while (i < data->count.l_count)
	{
		v_tmp = plane_light(ray, plane, data->objs[2 + i++]->u_data.light);
		if (map(v_tmp) > map(value))		//maybe can remove to make program faster;
			value = v_tmp;
	}
	//if (value)
	return (value);//can optimize
	//return 0;
}
