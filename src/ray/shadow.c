
#include "../../includes/minirt.h"

// checks whether a light source is the first one to reach a point on a ray.
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

// Calculates if a plane is facing the camera and the light source.
int	shadow_plane(t_light light, t_data *data, t_plane plane)
{
	t_cam cam;
	float	f1;
	float	f2;

	cam = data->objs[1]->u_data.camera;
	t_vec v_plane = vec_subs(cam.pos, plane.point);
	t_vec v_light = vec_subs(light.pos, plane.point);

	v_plane = vec_unit(v_plane);
	v_light = vec_unit(v_light);

	f1 = vec_dot(v_plane, plane.orient);
	f2 = vec_dot(v_light, plane.orient);

	if ((f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0))
		return (1);
	return (0);
}

// Determines if a sphere is blocking the light source from reaching
// the point of intersection between the ray and the object.
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

int	shadow_cylinder(t_data *data, int i, t_vec point_at, t_light light)
{
	float	root;
	t_vec	l2int;
	t_vec	root_at;
	int		ret = 0;
	t_vec	l2cyl;

	l2int = vec_subs(point_at, light.pos);
	l2cyl = vec_subs(light.pos, data->objs[i]->u_data.cylinder.center);
	root = hit_cylinder(l2int, data->objs[i]->u_data.cylinder, light.pos, l2cyl);
	root_at = vec_add(light.pos, vec_scale(root, l2int));
	if (!(root >= 0 && !is_first_light(light, point_at, root_at)))
		ret = 1;
	return (ret);
}

int	shadow_hyp(t_data *data, int i, t_vec point_at, t_light light)
{
	float	root;
	t_vec	l2int;
	t_vec	root_at;
	int		ret = 0;

	l2int = vec_subs(point_at, light.pos);
	root = hit_hyperboloid(l2int, data->objs[i]->u_data.hyperboloid, light.pos);
	root_at = vec_add(light.pos, vec_scale(root, l2int));
	if (!(root >= 0 && !is_first_light(light, point_at, root_at)))
		ret = 1;
	return (ret);
}