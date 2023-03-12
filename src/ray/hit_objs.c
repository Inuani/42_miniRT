
#include "../../includes/minirt.h"

int	is_first(t_vec r_point_at, t_cam cam, t_vec *point_at, int *first)
{
	t_vec	vector;
	t_vec	vector2;

	if (*first)
	{
		*first = 0;
		point_at->x = r_point_at.x;
		point_at->y = r_point_at.y;
		point_at->z = r_point_at.z;
		return (1);
	}
	vector = vec_subs(r_point_at, cam.pos);
	vector2 = vec_subs(*point_at, cam.pos);
	if (vec_len(vector2) < vec_len(vector))
		return (0);
	point_at->x = r_point_at.x;
	point_at->y = r_point_at.y;
	point_at->z = r_point_at.z;
	return (1);
}

int	first_objs(t_data *data, t_ray *ray)
{
	int		i;
	t_vec	point_at;
	t_cam	cam;

	cam = data->objs[1]->u_data.camera;
	ray->first = 1;
	ray->obj_n = 0;
	point_at = (t_vec){cam.pos.x, cam.pos.y, cam.pos.z};
	i = 2 + data->count.l_count - 1;
	while (data->objs[++i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
			is_sphere(data, ray, &point_at, i);
		else if (i < 2 + data->count.l_count + data->count.sp_count
			+ data->count.pl_count)
			is_plane(data, ray, &point_at, i);
		else if (i < 2 + data->count.l_count + data->count.sp_count
			+ data->count.pl_count + data->count.cy_count)
			is_cylinder(data, ray, &point_at, i);
		else if (i < 2 + data->count.l_count + data->count.sp_count
			+ data->count.pl_count + data->count.cy_count
			+ data->count.hy_count)
			is_hyperboloid(data, ray, &point_at, i);
	}
	return (ray->obj_n);
}

void	hit_objs(t_data *data, t_ray *ray)
{
	int	first_obj;

	first_obj = first_objs(data, ray);
	if (!first_obj)
		return ;
	if (first_obj < 2 + data->count.l_count + data->count.sp_count)
		it_hit_sphere(data, ray, data->objs[first_obj]->u_data.sphere);
	else if (first_obj < 2 + data->count.l_count + data->count.sp_count
		+ data->count.pl_count)
		plane_life(data, ray, data->objs[first_obj]->u_data.plane);
	else if (first_obj < 2 + data->count.l_count + data->count.sp_count
		+ data->count.pl_count + data->count.cy_count)
		cylinder_eman(data, ray, data->objs[first_obj]->u_data.cylinder);
	else if (first_obj < 2 + data->count.l_count + data->count.sp_count
		+ data->count.pl_count + data->count.cy_count + data->count.hy_count)
		it_hit_hy(data, ray, data->objs[first_obj]->u_data.hyperboloid);
}

// Checks if any of the objects in the scene are blocking the light source.
float	light_hit_objs(t_data *data, t_vec point_at, t_light light)
{
	int	i;
	int	ret;

	i = 2 + data->count.l_count;
	while (data->objs[i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
			ret = shadow_sphere(data, i, point_at, light);
		else if (i < 2 + data->count.l_count + data->count.sp_count
			+ data->count.pl_count)
			ret = shadow_plane(light, data, data->objs[i]->u_data.plane);
		else if (i < 2 + data->count.l_count + data->count.sp_count
			+ data->count.pl_count + data->count.cy_count)
			ret = shadow_cylinder(data, i, point_at, light);
		else if (i < 2 + data->count.l_count + data->count.sp_count
			+ data->count.pl_count + data->count.cy_count
			+ data->count.hy_count)
			ret = shadow_hyp(data, i, point_at, light);
		if (!ret)
			return (0);
		i++;
	}
	return (1);
}
