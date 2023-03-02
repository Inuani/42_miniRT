# include "../includes/minirt.h"

// local coordinate system for the cylinder ?

float hit_cylinder(t_vec ray_dir, t_vec cam2cyl, t_cylinder cylinder)
{
	// float	a; 
	// float	b; 
	// float	c;
	// float	delta;
	// float	t1;
	// float	t2;
	// float	y1;
	// float	y2;

	// a = ray_dir.x * ray_dir.x + ray_dir.z * ray_dir.z;
	// b = 2 * (ray_dir.x * cam2cyl.x + ray_dir.z * cam2cyl.z);
	// c = cam2cyl.x * cam2cyl.x + cam2cyl.z * cam2cyl.z - cylinder.radius * cylinder.radius;
	// delta = b * b - 4 * a * c;
	// if (delta < 0)
	// 	return -1;
	// t1 = (-b - sqrt(delta)) / (2 * a);
	// t2 = (-b + sqrt(delta)) / (2 * a);
	// y1 = cam2cyl.y + t1 * ray_dir.y;
	// y2 = cam2cyl.y + t2 * ray_dir.y;

	// if (y1 < 0 || y1 > cylinder.hgt)
	// 	t1 = -1;
	// if (y2 < 0 || y2 > cylinder.hgt)
	// 	t2 = -1;
	// if (t1 > 0 && t2 > 0)
	// 	return (t1 < t2 ? t1 : t2);
	// else
	// 	return (t1 > 0 ? t1 : t2);

	float a, b, c, delta, t1, t2, y1, y2;
	t_vec cyl_orient = cylinder.orient;
	t_vec dir_ortho = vec_subs(ray_dir, vec_scale(vec_dot(ray_dir, cyl_orient), cyl_orient));

	a = vec_dot(dir_ortho, dir_ortho);
	b = 2 * vec_dot(dir_ortho, vec_subs(cam2cyl, vec_scale(vec_dot(cam2cyl, cyl_orient), cyl_orient)));
	c = vec_dot(vec_subs(cam2cyl, vec_scale(vec_dot(cam2cyl, cyl_orient), cyl_orient)), vec_subs(cam2cyl, vec_scale(vec_dot(cam2cyl, cyl_orient), cyl_orient))) - pow(vec_dot(cam2cyl, cyl_orient), 2) - cylinder.radius * cylinder.radius;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return -1;
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	y1 = cam2cyl.y + t1 * ray_dir.y;
	y2 = cam2cyl.y + t2 * ray_dir.y;

	if (y1 < 0 || y1 > cylinder.hgt)
		t1 = -1;
	if (y2 < 0 || y2 > cylinder.hgt)
		t2 = -1;
	if (t1 > 0 && t2 > 0)
		return (t1 < t2 ? t1 : t2);
	else
		return (t1 > 0 ? t1 : t2);
}

float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl)
{
	t_cam	cam;
	t_vec	cam2cyl;
	float	hot_or_not;

	cam = data->objs[1]->u_data.camera;
	cam2cyl = vec_subs(cam.pos, cyl.center);
	hot_or_not = hit_cylinder(ray->direction, cam2cyl, cyl);
	if (hot_or_not < 0)
		return (-1);
	return(0);


}