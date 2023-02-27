
#include "../includes/minirt.h"

int	is_first(t_ray *ray, t_cam cam, t_vec point_at)
{
	t_vec vector;
	t_vec vector2;

	vector = vec_subs(ray->point_at, cam.pos); //maybe other side.
	vector2 = vec_subs(point_at, cam.pos);

	//printf_vec(vector);
	//printf_vec(vector2);
	if (vec_len(vector) < vec_len(vector2))
	{
		point_at.x = ray->point_at.x;
		point_at.y = ray->point_at.y;
		point_at.z = ray->point_at.z;
		return (1);
	}
	return (0);
}

float hit_objs(t_data *data, t_ray *ray, t_vec *colors)
{
	int			i;
	float		tmp;
	float		ret;
	t_vec		point_at;

	ret = -1;
	point_at = (t_vec){99, 99, 99};
	i = 2 + data->count.l_count;
	while (data->objs[i])
	{
		if (i < 2 + data->count.l_count + data->count.sp_count)
		{
			tmp = it_hit_sphere(data, ray, data->objs[i]->u_data.sphere);
			if (is_first(ray, data->objs[1]->u_data.camera, point_at))
			{
				ret = tmp;
				colors->x = data->objs[i]->u_data.sphere.colors.x;
				colors->y = data->objs[i]->u_data.sphere.colors.y;
				colors->z = data->objs[i]->u_data.sphere.colors.z;
			}
		}
		else if (i < 2 + data->count.l_count + data->count.sp_count
				+ data->count.pl_count)
			tmp = plane_life(data, ray, data->objs[i]->u_data.plane);
			if (is_first(ray, data->objs[1]->u_data.camera, point_at))
			{
				ret = tmp;
				colors->x = data->objs[i]->u_data.plane.colors.x;
				colors->y = data->objs[i]->u_data.plane.colors.y;
				colors->z = data->objs[i]->u_data.plane.colors.z;
			}
		//else if (i < 2 + data->count.l_count + data->count.sp_count
		//		+ data->count.pl_count + data->count.cy_count)
		i++;
	}
	//printf("%f\n", ret);
	return ret;
}