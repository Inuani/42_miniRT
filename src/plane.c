
#include "../includes/minirt.h"

t_plane	*create_plane(t_vec coords, t_vec orient, t_vec colors)
{
	t_plane *plane = malloc(sizeof(t_plane));

	plane->point.x = coords.x;
	plane->point.y = coords.y;
	plane->point.z = coords.z;

	plane->orientation.x = orient.x;
	plane->orientation.y = orient.y;
	plane->orientation.z = orient.z;

	plane->colors.x = colors.x;
	plane->colors.y = colors.y;
	plane->colors.z = colors.z;

	return (plane);
}

int	plane_hit(t_data *data, t_ray *ray, t_plane *plane)
{
	float	t;
	float	numer;
	float	denom;
	t_cam	*cam;

	cam = (t_cam*)data->objs[1];
	numer = vec_dot(vec_subs(plane->point, cam->coords), plane->orientation);
	denom = vec_dot(ray->direction, plane->orientation);

	t = (float)numer / (float)denom;

	if (t < 0)
		return -1;
	else
		return 1;
}

int	plane_life(t_data *data, t_ray *ray)
{
	t_vec pl_coords = {0, -1 ,0};
	t_vec pl_colors = {0, 30, 150};
	t_vec pl_orien = {0, -1, 0};
	t_plane	*plane;

	pl_orien = vec_unit(pl_orien);
	plane = create_plane(pl_coords, pl_orien, pl_colors);

	if (plane_hit(data, ray, plane) > 0)
		return 1;
	return 0;
}
