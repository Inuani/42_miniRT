# include "../includes/minirt.h"

// float	hit_cylinder(t_vec ray_dir, t_vec cam2cyl, t_cylinder cyl, t_vec origin)
// {
// 	t_vec	new_dir;
// 	t_vec	new_origin;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	t1;
// 	float	t2;
// 	float	delta;

// 	new_origin = origin;
// 	cyl.orient = vec_unit(cyl.orient);
// 	new_dir = vec_cross(ray_dir, cyl.orient);
// 	a = vec_dot(new_dir, new_dir);
// 	b = 2 * vec_dot(new_dir, vec_cross(cam2cyl, cyl.orient));
// 	c = vec_dot(vec_cross(cam2cyl, cyl.orient), vec_cross(cam2cyl, cyl.orient)) - powf(cyl.radius, 2.0);
// 	delta = powf(b, 2) - 4 * c * a;

// 	if (delta == 0.0)
// 	{
// 		// if (fabs(vec_dot(vec_unit(ray_dir), h)) != 1)
// 		// 	return(-(b / (2.0 * a)));
// 		// else if (fabs(vec_dot(vec_unit(ray_dir), h)) == 1)
// 		// {
// 				t1 = (-b - sqrt(delta)) / (2.0 * a);
// 				t2 = (-b + sqrt(delta)) / (2.0 * a);

// 			if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
// 				return (t1);
// 			return (t2);
// 		// }
// 	}
// 	else if (delta > 0)
// 	{
// 			t1 = (-b - sqrt(delta)) / (2.0 * a);
// 			t2 = (-b + sqrt(delta)) / (2.0 * a);

// 		if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
// 			return (t1);
// 		return (t2);
// 	}
// 	return (-1.0);
// }

float	hit_cylinder(t_vec ray_dir, t_vec cam2cyl, t_cylinder cyl)
{
	t_vec	h;
	t_vec	top_cyl;
	float	a;
	float	b;
	float	c;
	float	t1;
	float	t2;
	float	delta;

	cyl.orient = vec_unit(cyl.orient);
	// printf("---------\n");
	// printf_vec(cyl_ori_unit);
	top_cyl = vec_add(cyl.center, vec_scale(cyl.hgt, cyl.orient));
	// printf_vec(top_cyl);
	// h = vec_div(vec_subs(top_cyl, cyl.center), vec_unit(vec_subs(top_cyl, cyl.center)));

	h = vec_unit(vec_subs(top_cyl, cyl.center));
	//printf_vec(h);
	// printf("---------\n");
	a = vec_dot(ray_dir, ray_dir) - powf(vec_dot(ray_dir, h), 2.0);
	b = 2.0 * ((vec_dot(ray_dir, cam2cyl)) - (vec_dot(ray_dir, h) * vec_dot(cam2cyl, h)));
	c = vec_dot(cam2cyl, cam2cyl) - powf(vec_dot(cam2cyl, h), 2.0) - powf(cyl.radius, 2.0);
	delta = (b * b) - (4 * a * c);
	
	// printf("%f, %f, %f, %f\n", a, b, c, delta);
	if (delta == 0.0)
	{
		if (fabs(vec_dot(vec_unit(ray_dir), h)) != 1)
			return(-(b / (2.0 * a)));
		else if (fabs(vec_dot(vec_unit(ray_dir), h)) == 1)
		{
				t1 = (-b - sqrt(delta)) / (2.0 * a);
				t2 = (-b + sqrt(delta)) / (2.0 * a);

			if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
				return (t1);
			return (t2);
		}
	}
	else if (delta > 0)
	{
		t1 = (-b - sqrt(delta)) / (2.0 * a);
		t2 = (-b + sqrt(delta)) / (2.0 * a);
		if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
			return (t1);
		return (t2);
	}
	return (-1.0);
}

float	cylinder_eman(t_data *data, t_ray *ray, t_cylinder cyl)
{
	t_cam	cam;
	t_vec	cam2cyl;
	float	hot_or_not;

	cam = data->objs[1]->u_data.camera;
	// printf_vec()
	cam2cyl = vec_subs(cam.pos, cyl.center);
	// cam2cyl = vec_unit(vec_subs(cam.pos, cyl.center));
	// hot_or_not = hit_cylinder(ray->direction, cam2cyl, cyl);
	hot_or_not = hit_cylinder(ray->direction, cam2cyl, cyl);
	// printf("hot or not : %f\n", hot_or_not);
	if (hot_or_not < 0)
		return (-1);
	cyl.h = vec_subs(vec_add(cyl.center, vec_scale(cyl.hgt, cyl.orient)), cyl.center);
	ray->point_at = vec_add(cam.pos, vec_scale(hot_or_not, ray->direction));
	// printf_vec(ray->point_at);
	// printf("vec len: %f\n", vec_len(cyl.h));
	// printf_vec(cyl.h);
	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
		return -1;
	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_len(cyl.h))
		return -1;
	return(0);
}

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

	// float a, b, c, delta, t1, t2, y1, y2;
	// t_vec cyl_orient = cylinder.orient;
	// t_vec dir_ortho = vec_subs(ray_dir, vec_scale(vec_dot(ray_dir, cyl_orient), cyl_orient));

	// a = vec_dot(dir_ortho, dir_ortho);
	// b = 2 * vec_dot(dir_ortho, vec_subs(cam2cyl, vec_scale(vec_dot(cam2cyl, cyl_orient), cyl_orient)));
	// c = vec_dot(vec_subs(cam2cyl, vec_scale(vec_dot(cam2cyl, cyl_orient), cyl_orient)), vec_subs(cam2cyl, vec_scale(vec_dot(cam2cyl, cyl_orient), cyl_orient))) - pow(vec_dot(cam2cyl, cyl_orient), 2) - cylinder.radius * cylinder.radius;
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








// float a;
	// float b;
	// float c;
	// float delta;
	// float root;

    // a = ray_dir.x * ray_dir.x + ray_dir.z * ray_dir.z;
    // b = 2 * ray_dir.x * (cam_pos.x - cyl.center.x) + 2 * ray_dir.z * (ray->ori->z - cylinder->base->z);
    // c = (ray->ori->x - cylinder->base->x) * (ray->ori->x - cylinder->base->x) + (ray->ori->z - cylinder->base->z) * (ray->ori->z - cylinder->base->z) - cylinder->radius * cylinder->radius;

    // delta = b * b - 4 * a * c;
    // if (delta > ACC)
    // {
    //         root = (-1 * b - sqrt(delta)) / 2 * a - ACC;
    //         if (root <= ACC)
    //                 root = (-1 * b + sqrt(delta)) / 2 * a - ACC;
    //         return (root);
    // }
    // return (-1);

	// float	a; 
	// float	b; 
	// float	c;
	// float	delta;
	// float	t1;
	// float	t2;
	// float	y1;
	// float	y2;

	// a = ray_dir.x * ray_dir.x + ray_dir.z * ray_dir.z;
	// b = ray_dir.x * ()
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