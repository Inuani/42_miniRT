#include "../../includes/minirt.h"

float	vec_dot(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec	vec_cross(t_vec vec1, t_vec vec2)
{
	t_vec result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}

float	vec_len(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec	vec_unit(t_vec vec)
{
	t_vec	result;
	float	len;
	
	len = vec_len(vec);
	result.x = vec.x / len;
	result.y = vec.y / len;
	result.z = vec.z / len;
	return (result);
}

t_vec	vec_abs(t_vec vec)
{
	t_vec	res;

	res.x = fabs(vec.x);
	res.y = fabs(vec.y);
	res.z = fabs(vec.z);
	return(res);
}

//works with unit vectors !
float	get_angle_0_to_1(t_vec normal, t_vec obj)
{
	float	dot;
	float	angle;
	dot = vec_dot(normal, obj);
	angle = acos(dot);
	return (angle / (M_PI));
}

int	get_angle_degree(t_vec normal, t_vec ray_l)
{
	float dot = vec_dot(normal, ray_l);
	float magnitude_n = vec_len(normal);
	float magnitude_l = vec_len(ray_l);
	float angle = acos(dot / (magnitude_n * magnitude_l));
	return (angle * 180.0 / M_PI);
}