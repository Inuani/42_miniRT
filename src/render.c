
#include "../includes/minirt.h"

void	print_color(t_data *data, t_vec color)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	t_img *img = mlx_new_image(data->mlx, 150, 50);
	img->addr = mlx_get_data_addr(img, &img->bits_per_pixel,
			&img->line_length, &img->endian);

	while (i < 50)
	{
		while (j < 50)
			my_mlx_pixel_put(img, 0 + i, 0 + j++, create_trgb(0, color.x, 0, 0));
		i++;
		j = 0;
	}
	i = 0;
	while (i < 50)
	{
		while (j < 50)
			my_mlx_pixel_put(img, 50 + i, 0 + j++, create_trgb(0, 0, color.y, 0));
		i++;
		j = 0;
	}
	i = 0;
	while (i < 50)
	{
		while (j < 50)
			my_mlx_pixel_put(img, 100 + i, 0 + j++, create_trgb(0, 0, 0, color.z));
		i++;
		j = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win, img, 5, 5);
}

char *floatToString(float num, char *str) {
	sprintf(str, "%.1f", num);
	return str;
}

//2 + data->count.l_count + data->count.sp_count + data->count.pl_count

void render_text(t_data *data)
{
	char str[32];
	if (data->current == 0)
	{
		if (data->changed)
			printf("\nYou are on ambient light.\nUse I to increase light, K to decrease.\n7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/30, HEIGHT - HEIGHT/19, 0xFFFFFF, "You are on ambient");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - 80, HEIGHT - HEIGHT/30, 0xFFFFFF, "light intensity : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 60, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[0]->u_data.ambiant.light_ratio, str));
		print_color(data, data->objs[0]->u_data.ambiant.colors);
	}
	else if (data->current == 1)
	{
		if (data->changed)
			printf("\nYou are on camera.\nUse P to increase FOV, ; to decrease.\nQ W E to increase coords components\nA S D to decrease them\nU I O and J K L to change the orientation\n\n");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/30, HEIGHT - HEIGHT/19, 0xFFFFFF, "You are on camera");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/20, HEIGHT - HEIGHT/30, 0xFFFFFF, "cam coords : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 10, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[1]->u_data.camera.pos.x, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 50, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[1]->u_data.camera.pos.y, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 90, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[1]->u_data.camera.pos.z, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 - 75, HEIGHT - HEIGHT/55, 0xFFFFFF, "cam FOV : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 10, HEIGHT - HEIGHT/55, 0xFFFFFF, floatToString(data->objs[1]->u_data.camera.fov, str));
	}
	else if (data->current < 2 + data->count.l_count)
	{
		if (data->changed)
			printf("\nYou are on a light.\nUse I to increase light, K to decrease.\nQ W E to increase coords components\nA S D to decrease them\n7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/30, HEIGHT - HEIGHT/19, 0xFFFFFF, "You are on a light");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/20 -20, HEIGHT - HEIGHT/30, 0xFFFFFF, "light coords : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.light.pos.x, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 40, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.light.pos.y, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 90, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.light.pos.z, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 - 80, HEIGHT - HEIGHT/55, 0xFFFFFF, "light intensity : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 50, HEIGHT - HEIGHT/55, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.light.light_ratio, str));
		print_color(data, data->objs[data->current]->u_data.light.colors);
	}
	else if (data->current < 2 + data->count.l_count + data->count.sp_count)
	{
		if (data->changed)
			printf("\nYou are on a sphere.\nUse I to increase radius, K to decrease.\nQ W E to increase coords components\nA S D to decrease them\n7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/30, HEIGHT - HEIGHT/19, 0xFFFFFF, "You are on a sphere");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 20- WIDTH/20 -80, HEIGHT - HEIGHT/30, 0xFFFFFF, "sphere center coords : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 10, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.sphere.center.x, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 60, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.sphere.center.y, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 110, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.sphere.center.z, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 - 70, HEIGHT - HEIGHT/55, 0xFFFFFF, "sphere radius : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 50, HEIGHT - HEIGHT/55, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.sphere.radius, str));
		print_color(data, data->objs[data->current]->u_data.sphere.colors);
	}
	else if (data->current < 2 + data->count.l_count + data->count.sp_count + data->count.pl_count)
	{
		if (data->changed)
			printf("\nYou are on a plane.\nUse W E to increase coords components\nA S D to decrease them.\nU I O and J K L to change the orientation\n7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/30, HEIGHT - HEIGHT/19, 0xFFFFFF, "You are on a plane");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 20- WIDTH/20 -80, HEIGHT - HEIGHT/30, 0xFFFFFF, "plane center coords : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 10, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.plane.point.x, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 60, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.plane.point.y, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 110, HEIGHT - HEIGHT/30, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.plane.point.z, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 - 140, HEIGHT - HEIGHT/55, 0xFFFFFF, "plane orientation : ");
		mlx_string_put(data->mlx, data->win, WIDTH/2, HEIGHT - HEIGHT/55, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.plane.orient.x, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 50, HEIGHT - HEIGHT/55, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.plane.orient.y, str));
		mlx_string_put(data->mlx, data->win, WIDTH/2 + 100, HEIGHT - HEIGHT/55, 0xFFFFFF, floatToString(data->objs[data->current]->u_data.plane.orient.z, str));
		print_color(data, data->objs[data->current]->u_data.plane.colors);
	}
	else
	{
		mlx_string_put(data->mlx, data->win, WIDTH/2 - WIDTH/30, HEIGHT - HEIGHT/19, 0xFFFFFF, "You are on a cylinder");
	}
	data->changed = 0;
}

void render(t_data *data)
{
	int		i;
	int		j;
	float	u;
	float	v;
	//int spp = 0;

	i = -1;
	j = HEIGHT - 1;
	while (j-- > 0)
	{
		while (++i < WIDTH)
		{
		//	while (spp < data->vp->samplespp)
		//	{
			// u = ((float)(i) + rand_double(i)) / (float)(WIDTH - 1);
			// v = ((float)(j) + rand_double(j)) / (float)(HEIGHT - 1);
			u = (float)(i) / (float)(WIDTH - 1);
			v = (float)(j) / (float)(HEIGHT - 1);
			t_ray ray = create_ray(&data->objs[1]->u_data.camera, data->vp, u, v);
			my_mlx_pixel_put(&(data->img), i, j, ray_color(&ray, data));
		//		spp++;
		//	}
		//	spp = 0;
		}
		i = -1;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	render_text(data);

}