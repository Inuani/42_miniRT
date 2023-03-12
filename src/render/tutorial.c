
#include "../../includes/minirt.h"

void	ambient_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on ambient light.\nUse I to increase light, ");
		printf("K to decrease.\n");
		printf("7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on ambient");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 80,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "light intensity : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 60,
		HEIGHT - HEIGHT / 30, 0xFFFFFF,
		fts(data->objs[0]->u_data.ambiant.light_ratio, str));
}

void	camera_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on camera.\nUse P to increase FOV, ; to decrease.\n");
		printf("Q W E to increase coords components\nA S D to decrease them\n");
		printf("U I O and J K L to change the orientation\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on camera");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 20,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "cam coords : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 10, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[1]->u_data.camera.pos.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 50, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[1]->u_data.camera.pos.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 90, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[1]->u_data.camera.pos.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 75, HEIGHT - HEIGHT / 55,
		0xFFFFFF, "cam FOV : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 10, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[1]->u_data.camera.fov, str));
}

void	light_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on a light.\nUse I to increase light, K to decrease.\n");
		printf("Q W E to increase coords components\nA S D to decrease them\n");
		printf("7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a light");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 20 -20,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "light coords : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.light.pos.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 40, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.light.pos.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 90, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.light.pos.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 80, HEIGHT - HEIGHT / 55,
		0xFFFFFF, "light intensity : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 50, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.light.light_ratio,
			str));
}

void	cylinder_text_p2(t_data *data, char *str)
{
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 110, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - 140, HEIGHT - HEIGHT / 55,
		0xFFFFFF, "cylinder orientation : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 50, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.y, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 100, HEIGHT - HEIGHT / 55,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.orient.z, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a cylinder");
}

void	cylinder_text(t_data *data)
{
	char	str[32];

	if (data->changed)
	{
		printf("\nYou are on a cylinder.\nUse W E to increase coords");
		printf(" components\nA S D to decrease them.\nU I O and J K L to");
		printf(" change the orientation\n");
		printf("7 8 9 to increase colors components\n4 5 6 to decrease them\n\n");
	}
	mlx_string_put(data->mlx, data->win, WIDTH / 2 - WIDTH / 30,
		HEIGHT - HEIGHT / 19, 0xFFFFFF, "You are on a cylinder");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 20 - WIDTH / 20 - 80,
		HEIGHT - HEIGHT / 30, 0xFFFFFF, "cylinder center coords : ");
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 10, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.x, str));
	mlx_string_put(data->mlx, data->win, WIDTH / 2 + 60, HEIGHT - HEIGHT / 30,
		0xFFFFFF, fts(data->objs[data->current]->u_data.plane.point.y, str));
	cylinder_text_p2(data, str);
}
