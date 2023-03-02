# include "../includes/minirt.h"

// local coordinate system for the cylinder ?

float	hit_cylinder(t_vec ray_dir, t_vec cam2cyl, t_cylinder cylinder)
{
	float	a; 
	float	b; 
	float	c;
	float	delta;
	float	t;

	a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y;
	b = 2 * (ray_dir.x * cam2cyl.x + ray_dir.y * cam2cyl.y);
	c = cam2cyl.x * cam2cyl.x + cam2cyl.y * cam2cyl.y - (cylinder.diameter / 2) * (cylinder.diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	t = (-b - sqrt(delta)) / (2 * a);
	if (t > 0 && t < cylinder.hgt)
		return (t);
	t = (-b + sqrt(delta)) / (2 * a);
	if (t > 0 && t < cylinder.hgt)
		return (t);
	return (-1);
}

float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl)
{
	t_cam	cam;
	t_vec	cam2cyl;
	float	hot_or_not;

	cam = data->objs[1]->u_data.camera;
	cam2cyl = vec_subs(cam.pos, cyl.base);
	hot_or_not = hit_cylinder(ray.direction, cam2cyl, cyl);
	if ()


}