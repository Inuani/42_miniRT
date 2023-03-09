
#include "../../includes/minirt.h"

/*
int equal (t_vec vec, t_vec vec2)
{
	if (vec.x == vec2.x && vec.y == vec2.y && vec.z == vec2.z)
		return (1);
	return (0);
}*/

int	is_first(t_vec r_point_at, t_cam cam, t_vec *point_at, int *first)
{
	t_vec vector;
	t_vec vector2;
	
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

// This function checks which object in the scene
// is the first to intersect with the ray.
// It iterates over all the objects in the scene and checks
// whether the ray intersects with them.
// is_first is used to keep track of the closest intersection point found so far.
int	first_objs(t_data *data, t_ray *ray)
{
	int		i;
	t_vec	point_at;
	t_vec	r_point_at;
	t_cam	cam;
	float	root;

	cam = data->objs[1]->u_data.camera;
	ray->first = 1;
	ray->obj_n = 0;
	point_at = (t_vec){cam.pos.x, cam.pos.y, cam.pos.z};
	i = 2 + data->count.l_count;
	while (data->objs[i])
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
				+ data->count.pl_count + data->count.cy_count + data->count.hy_count)
		{
			root = hit_hyperboloid(ray->direction, data->objs[i]->u_data.hyperboloid, cam.pos);
			//printf("%f\n", root);
			if (root > 0)
			{
				//r_point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
				//if (is_first(r_point_at, cam, &point_at, &first))
				//{
				ray->point_at.x = r_point_at.x;
				ray->point_at.y = r_point_at.y;
				ray->point_at.z = r_point_at.z;
				ray->obj_n = i;
				//}
				
			}
		}
		i++;
	}
	return (ray->obj_n);
}

void hit_objs(t_data *data, t_ray *ray)
{
	int	first_obj = first_objs(data, ray);

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
float light_hit_objs(t_data *data, t_ray *ray, t_vec point_at, t_light light)
{
	int		i;

	(void)ray;
	i = 2 + data->count.l_count;

	while (data->objs[i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
		{
			if (!shadow_sphere(data, i, point_at, light))
				return (0);
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count)
		{
			if (!shadow_plane(data, i, light))
				return (0);
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count + data->count.cy_count)
		{
			if (!shadow_cylinder(data, i, point_at, light))
				return (0);
		}
		i++;
	}
	return (1);
}