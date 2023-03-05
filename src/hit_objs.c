
#include "../includes/minirt.h"

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

int	first_objs(t_data *data, t_ray *ray)
{
	int		i;
	float	root;
	int		obj_n;
	int		first;
	t_cam	cam;
	t_vec	point_at;
	t_vec	r_point_at;

	first = 1;
	obj_n = 0;
	point_at = (t_vec){cam.pos.x, cam.pos.y, cam.pos.z};
	cam = data->objs[1]->u_data.camera;

	i = 2 + data->count.l_count;
	while (data->objs[i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
		{
			t_vec v = vec_subs(cam.pos, data->objs[i]->u_data.sphere.center);
			root = sphere_hits(ray->direction, v, data->objs[i]->u_data.sphere);
			if (root > 0)
			{
				r_point_at = vec_add(cam.pos, vec_scale(root, ray->direction));
				if (is_first(r_point_at, cam, &point_at, &first))
				{
					ray->point_at.x = r_point_at.x;
					ray->point_at.y = r_point_at.y;
					ray->point_at.z = r_point_at.z;
					obj_n = i;
				}
			}
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count)
		{
			root = plane_hit(&data->objs[i]->u_data.plane, cam.pos, ray->direction);
			if (root > 0)
			{
				r_point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
				if (is_first(r_point_at, cam, &point_at, &first))
				{
					ray->point_at.x = r_point_at.x;
					ray->point_at.y = r_point_at.y;
					ray->point_at.z = r_point_at.z;
					obj_n = i;
				}
			}
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count + data->count.cy_count)
		{
			cylinder_init(data, &data->objs[i]->u_data.cylinder);
			root = hit_cylinder(ray, data->objs[i]->u_data.cylinder, data->objs[1]->u_data.camera.pos);
			if (root > 0)
			{
				r_point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
				if (is_first(r_point_at, cam, &point_at, &first))
				{
					ray->point_at.x = r_point_at.x;
					ray->point_at.y = r_point_at.y;
					ray->point_at.z = r_point_at.z;
					obj_n = i;
				}
			}
		}
		i++;
	}
	return (obj_n);
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
}

int	is_first_light(t_light light, t_vec point_at, t_vec root_at)
{
	t_vec vector;
	t_vec vector2;

	vector = vec_subs(point_at, light.pos);
	vector2 = vec_subs(root_at, light.pos);

	if (vec_len(vector) - 0.01 <= vec_len(vector2)) //maybe needs offset
		return (1);
	return (0);
}

int is_light_plane(t_light light, t_data *data, t_plane plane)
{
	t_cam cam;
	float f1;
	float f2;
	
	cam = data->objs[1]->u_data.camera;
	t_vec v_plane = vec_subs(cam.pos, plane.point);
	t_vec v_light = vec_subs(light.pos, plane.point);

	v_plane = vec_unit(v_plane);
	v_light = vec_unit(v_light);

	f1 = vec_dot(v_plane, plane.orient);
	f2 = vec_dot(v_light, plane.orient);

	if ((f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0))
		return 1;
	return 0;
}


int shadow_sphere(t_data *data, int i, t_vec point_at, t_light light)
{
	float	root;
	t_vec	vector;
	t_vec	v;
	t_vec	root_at;
	int		ret = 0;

	vector = vec_subs(point_at, light.pos);
	v = vec_subs(light.pos, data->objs[i]->u_data.sphere.center);
	root = sphere_hits(vector, v, data->objs[i]->u_data.sphere);
	root_at = vec_add(light.pos, vec_scale(root, vector));
	if (!(root >= 0 && !is_first_light(light, point_at, root_at)))
		ret = 1;
	return (ret);
}


int shadow_plane(t_data *data, int i, t_light light)
{
	int		ret = 0;

	if (!(!is_light_plane(light, data, data->objs[i]->u_data.plane)))
		ret = 1;
	return (ret);
}


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
		//else if (i < 2 + data->count.l_count + data->count.sp_count
		//		+ data->count.pl_count + data->count.cy_count)
		i++;
	}
	return 1;
}