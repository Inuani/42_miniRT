
#include "../../includes/minirt.h"

float inverse_map(float x)
{
	float	y;
	y = fabs(1 - x);
	return (0.0 +  ((1.0 - 0.0) / (float)(90.0 - 0)) * (y - 0));
}


void	phong_plane(t_data *data, t_ray *ray, t_light light, t_vec obj_color)
{
	t_vec	R;
	t_vec	dir;
	float	ln2;
	float	i_d;
	float	i_s;

	t_vec vector = vec_subs(light.pos, ray->point_at);
	vector = vec_unit(vector);
	ln2 = 2 * vec_dot(vector, ray->normal);
	R = vec_subs(vec_scale(ln2, ray->normal), vector);
	dir = ray->direction;
	i_d = vec_dot(vector, ray->normal) * light.light_ratio;
	i_s = 0;
	
	t_vec diffuse_color = add_color(vec_scale(K, obj_color), vec_scale(1 - K, light.colors));
	data->final_color = add_colors(data->final_color, diffuse_color, i_d);
	data->final_color = add_colors(data->final_color, light.colors, i_s);
}

float	plane_hit(t_plane *plane, t_vec ray_origine, t_vec ray_direction)
{
	float	t;
	float	numer;
	float	denom;

	numer = vec_dot(vec_subs(plane->point, ray_origine), plane->orient);
	denom = vec_dot(ray_direction, plane->orient);

	t = numer / denom;

	if (t < 0)
		return -1;
	return t;
}

// int getcolorofpixel(t_data *data, int *width, int	*height)
// {
// 	void	*img_data;
// 	img_data = mlx_xpm_file_to_image(data->mlx, "images/plaque_metal.xpm", width, height);

// 	printf("height : %d\n", height);
// 	printf("width : %d\n", width);

// 	int bpp;
// 	int size_line;
// 	int endian;
// 	char *img_info = mlx_get_data_addr(img_data, &bpp, &size_line, &endian);
// 	int x = 10;
// 	int y = 10;
// 	int	pixel_offset = (y * size_line) + (x * (bpp / 8));
// 	int	pixel_color = mlx_get_color_value(data->mlx, *(int *)(img_info + pixel_offset));
// 	return (pixel_color);
// }

// void get_texture(t_data *data, t_ray *ray, t_plane *plane)
// {
// 	int w;
// 	int h;
// 	int	x;
// 	int	y;
// 	t_vec	color;
// 	(void)plane;

// 	getcolorofpixel(data, &w, &h);
// 	x = ((int)ray->point_at.x % 2) / w;
// 	y = ((int)ray->point_at.z % 2) / h;

// 	color = decimalToRGB(getcolorofpixel(data, &w, &h));
// 	plane->colors = color;
// }

void	plane_light(t_data *data, t_ray *ray, t_plane plane, t_light light)
{
	if (!light_hit_objs(data, ray, ray->point_at, light))
		return ;

	// get_texture(data, ray, &plane);
	ray->normal = plane.orient;
	ray->shiny = 5;
	phong_plane(data, ray, light, plane.colors);
}


void	plane_life(t_data *data, t_ray *ray, t_plane plane)
{
	int		i;

	i = 0;

	while (i < data->count.l_count)
		plane_light(data, ray, plane, data->objs[2 + i++]->u_data.light);
	t_vec ambient_color = add_color(vec_scale(K, plane.colors), vec_scale(1 - K, data->objs[0]->u_data.ambiant.colors));
	data->final_color = add_colors(data->final_color, ambient_color, data->objs[0]->u_data.ambiant.light_ratio);
}
