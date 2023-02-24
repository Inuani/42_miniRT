
#include "../includes/minirt.h"

void render(t_data *data)
{
	int		i;
	int		j;
	float	u;
	float	v;

	i = -1;
	j = HEIGHT - 1;
	while (j-- > 0)
	{
		while (++i < WIDTH)
		{
			u = (float)(i) / (float)(WIDTH - 1);
			v = (float)(j) / (float)(HEIGHT - 1);
			t_ray ray = create_ray((t_cam*)data->objs[1], data->vp, u, v);
			my_mlx_pixel_put(&(data->img), i, j, ray_color(&ray, data));
		}
		i = -1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}