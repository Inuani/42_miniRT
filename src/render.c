
#include "../includes/minirt.h"

void render(t_data *data)
{
	int	i;
	int	j;
	int	u;
	int v;

	i = -1;
	j = -1;
	while (++j < HEIGHT)
	{
		while (++i < WIDTH)
		{
			u = (double)(i) / (double)(WIDTH - 1);
			v = (double)(i) / (double)(HEIGHT - 1);
			t_ray ray = create_ray((t_cam*)data->objs[1]);
			my_mlx_pixel_put(&(data->img), i, j, ray_color(&ray));
		}
		i = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}