
#include "../includes/minirt.h"


t_vec	vec_add(t_vec *vec1, t_vec *vec2)
{
	t_vec	result;
	result.x = vec1->x + vec2->x;
	result.y = vec1->y + vec2->y;
	result.z = vec1->z + vec2->z;
	return (result);
}

t_vec	vec_subs(t_vec *vec1, t_vec *vec2)
{
	t_vec	result;
	result.x = vec1->x - vec2->x;
	result.y = vec1->y - vec2->y;
	result.z = vec1->z - vec2->z;
	return (result);
}

t_vec	vec_mult(t_vec *vec1, t_vec *vec2)
{
	t_vec result;
	result.x = vec1->x * vec2->x;
	result.y = vec1->y * vec2->y;
	result.z = vec1->z * vec2->z;
	return (result);
}

t_vec	vec_scale(float nbr, t_vec *vec2)
{
	t_vec result;

	result.x = nbr * vec2->x;
	result.y = nbr * vec2->y;
	result.z = nbr * vec2->z;
	return (result);
}

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

t_vec	vec_normalisation(t_vec vec)
{
	t_vec	result;
	float	res = vec_len(vec);

	result.x = vec.x / res;
	result.y = vec.y / res;
	result.z = vec.z / res;
	return (result);
}
