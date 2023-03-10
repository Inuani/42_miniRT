
#include "../../includes/minirt.h"

void vec_equal(t_vec *vec1, t_vec *vec2)
{
	vec1->x = vec2->x;
	vec1->y = vec2->y;
	vec1->z = vec2->z;
}

void	is_sphere(t_data *data, t_ray *ray, t_vec *point_at, int i)
{
	t_cam	cam;
	t_vec	v;
	t_vec	r_point_at;
	float	root;

	cam = data->objs[1]->u_data.camera;
	v = vec_subs(cam.pos, data->objs[i]->u_data.sphere.center);
	root = sphere_hits(ray->direction, v, data->objs[i]->u_data.sphere);
	if (root > 0)
	{
		r_point_at = vec_add(cam.pos, vec_scale(root, ray->direction));
		if (is_first(r_point_at, cam, point_at, &ray->first))
		{
			vec_equal(&ray->point_at, &r_point_at);
			ray->obj_n = i;
		}
	}
}

void	is_plane(t_data *data, t_ray *ray, t_vec *point_at, int i)
{
	t_cam	cam;
	t_vec	r_point_at;
	float	root;

	cam = data->objs[1]->u_data.camera;
	root = plane_hit(&data->objs[i]->u_data.plane, cam.pos, ray->direction);
	if (root > 0)
	{
		r_point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
		if (is_first(r_point_at, cam, point_at, &ray->first))
		{
			vec_equal(&ray->point_at, &r_point_at);
			ray->obj_n = i;
		}
	}
}

void	is_cylinder(t_data *data, t_ray *ray, t_vec *point_at, int i)
{
	t_cam	cam;
	t_vec	r_point_at;
	float	root;

	cam = data->objs[1]->u_data.camera;
	cylinder_init(data, &data->objs[i]->u_data.cylinder);
	root = hit_cylinder(ray->direction, data->objs[i]->u_data.cylinder,
		cam.pos, data->objs[i]->u_data.cylinder.cam2cyl);
	if (root > 0)
	{
		r_point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
		if (is_first(r_point_at, cam, point_at, &ray->first))
		{
			vec_equal(&ray->point_at, &r_point_at);
			ray->obj_n = i;
		}
	}
}

void	is_hyperboloid(t_data *data, t_ray *ray, t_vec *point_at, int i)
{
	t_cam	cam;
	t_vec	r_point_at;
	float	root;

	cam = data->objs[1]->u_data.camera;
	
	root = hit_hyperboloid(ray->direction, data->objs[i]->u_data.hyperboloid, cam.pos);
	if (root > 0)
	{
		r_point_at = vec_add(data->objs[1]->u_data.camera.pos, vec_scale(root, ray->direction));
		if (is_first(r_point_at, cam, point_at, &ray->first))
		{
			vec_equal(&ray->point_at, &r_point_at);
			ray->obj_n = i;
		}
	}
}