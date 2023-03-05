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

	// printf("---------\n");
	// printf_vec(cyl.orient);
	cyl.orient = vec_unit(cyl.orient);
	// printf("cyl orient:\n");
	// printf_vec(cyl.orient);

	top_cyl = vec_add(cyl.center, vec_scale(cyl.hgt, cyl.orient));
	// printf("top cyl:\n");
	// printf_vec(top_cyl);
	h = vec_div_float(vec_subs(top_cyl, cyl.center), vec_len(vec_subs(top_cyl, cyl.center)));

	// h = vec_unit(vec_subs(top_cyl, cyl.center));
	// printf("vec h:\n");
	// printf_vec(h);
	// printf("---------\n");
	a = vec_dot(ray_dir, ray_dir) - powf(vec_dot(ray_dir, h), 2);
	b = 2.0 * ((vec_dot(ray_dir, cam2cyl)) - (vec_dot(ray_dir, h) * vec_dot(cam2cyl, h)));
	c = vec_dot(cam2cyl, cam2cyl) - powf(vec_dot(cam2cyl, h), 2) - powf(cyl.radius, 2.0);
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
		// verifier si t sont bien positif, sinon ils sont derriere la camera
		// if (t1 > 0.0 && (t2 < 0.0 || t1 < t2))
		if (t1 < t2)
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
	cam2cyl = vec_subs(cam.pos, cyl.center);
	hot_or_not = hit_cylinder(ray->direction, cam2cyl, cyl);
	// printf("hot or not : %f\n", hot_or_not);
	if (hot_or_not < 0)
		return (-1);
	cyl.h = vec_subs(vec_add(cyl.center, vec_scale(cyl.hgt, cyl.orient)), cyl.center);
	ray->point_at = vec_add(cam.pos, vec_scale(hot_or_not, ray->direction));
	// printf("---------\n");
	// printf("ray point at\n");
	// printf_vec(ray->point_at);
	// printf("vec len: %f\n\n", vec_len(cyl.h));
	// printf("vec cyl.h :\n");
	// printf_vec(cyl.h);
	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) < 0)
		return -1;
	// if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_len(cyl.h))
	if (vec_dot(vec_subs(ray->point_at, cyl.center), cyl.h) > vec_dot(cyl.h, cyl.h))
		return -1;
	return(0);
}
