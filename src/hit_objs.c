
#include "../includes/minirt.h"


int equal (t_vec vec, t_vec vec2)
{
	if (vec.x == vec2.x && vec.y == vec2.y && vec.z == vec2.z)
		return (1);
	return (0);
}

int	is_first(t_ray *ray, t_cam cam, t_vec *point_at)
{
	t_vec vector;
	t_vec vector2;
	
	if (equal(*point_at, cam.pos))
	{
		point_at->x = ray->point_at.x;
		point_at->y = ray->point_at.y;
		point_at->z = ray->point_at.z;
		return (1);
	}

	vector = vec_subs(ray->point_at, cam.pos);
	vector2 = vec_subs(*point_at, cam.pos);
	if (vec_len(vector2) < vec_len(vector))
		return (0);
	return (1);
}

float hit_objs(t_data *data, t_ray *ray, t_vec *colors)
{
	int			i;
	float		tmp;
	float		ret;
	t_vec		point_at;


	t_cam cam = data->objs[1]->u_data.camera;
	ret = -1;
	point_at = (t_vec){cam.pos.x, cam.pos.y, cam.pos.z};
	i = 2 + data->count.l_count;
	while (data->objs[i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
		{
			tmp = it_hit_sphere(data, ray, data->objs[i]->u_data.sphere);
			if (tmp != -1 && is_first(ray, data->objs[1]->u_data.camera, &point_at))
			{
				ret = tmp;
				colors->x = data->objs[i]->u_data.sphere.colors.x;
				colors->y = data->objs[i]->u_data.sphere.colors.y;
				colors->z = data->objs[i]->u_data.sphere.colors.z;
			}
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count)
		{
			tmp = plane_life(data, ray, data->objs[i]->u_data.plane);
			if (tmp != -1 && is_first(ray, data->objs[1]->u_data.camera, &point_at))
			{
				ret = tmp;
				colors->x = data->objs[i]->u_data.plane.colors.x;
				colors->y = data->objs[i]->u_data.plane.colors.y;
				colors->z = data->objs[i]->u_data.plane.colors.z;
			}
		}
		//else if (i < 2 + data->count.l_count + data->count.sp_count
		//		+ data->count.pl_count + data->count.cy_count)
		i++;
	}
	//printf("%f\n", ret);
	return ret;
}

int	is_first_light(t_light light, t_vec point_at, t_vec root_at)
{
	t_vec vector;
	t_vec vector2;

	vector = vec_subs(point_at, light.pos);
	vector2 = vec_subs(root_at, light.pos);

	if (vec_len(vector) - 0.01 <= vec_len(vector2)) //maybe needs offset
		return (1);
	
	//printf("--------------\n");
	//printf_vec(point_at);
	//printf_vec(root_at);
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

float light_hit_objs(t_data *data, t_ray *ray, t_vec point_at)
{
	float	root;
	int		i;

	(void)ray;
	t_light light = data->objs[2]->u_data.light;
	t_vec vector = vec_subs(point_at, light.pos);

	i = 2 + data->count.l_count;
	while (data->objs[i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
		{
			t_vec v = vec_subs(light.pos, data->objs[i]->u_data.sphere.center);
			root = sphere_hits(vector, v, data->objs[i]->u_data.sphere);
			t_vec root_at = vec_add(light.pos, vec_scale(root, vector));
			if (root >= 0 && !is_first_light(light, point_at, root_at))
			{
			//	printf("----------\n");
			//	printf_vec(point_at);
			//	printf_vec(root_at);

				return (0);
			}
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count)
		{
			if (!is_light_plane(light, data, data->objs[i]->u_data.plane))
				return (0);
		}
		//else if (i < 2 + data->count.l_count + data->count.sp_count
		//		+ data->count.pl_count + data->count.cy_count)
		i++;
	}
	return 1;
}