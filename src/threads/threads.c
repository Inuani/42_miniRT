
#include "../../includes/minirt.h"

//WIDTH / 6;
//HEIGH / 4;


void	create_thread(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->lock, 0);
	data->fin = 0;
	data->thread_id = malloc(sizeof(pthread_t) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		data->thread_i = i;
		pthread_create(&data->thread_id[i], NULL, render_thr, data);
		usleep(100);
		i++;
	}
	while (data->fin != 12) {}
	render_text(data);
	i = 0;
	free(data->thread_id);
}

t_object	*copy_obj_list_deep(const t_object *list)
{
	t_object	*new_node;

	if (list == NULL)
		return (NULL);
	new_node = malloc(sizeof(t_object));
	if (!new_node)
		return (NULL);
	new_node->type = list->type;
	new_node->next = NULL;
	if (list->next != NULL)
		new_node->next = copy_obj_list_deep(list->next);
	if (new_node->type == AMBIANT)
	{
		new_node->u_data.ambiant.light_ratio = list->u_data.ambiant.light_ratio;
		new_node->u_data.ambiant.colors.x = list->u_data.ambiant.colors.x;
		new_node->u_data.ambiant.colors.y = list->u_data.ambiant.colors.y;
		new_node->u_data.ambiant.colors.z = list->u_data.ambiant.colors.z;
	}
	else if (new_node->type == CAMERA)
	{
		new_node->u_data.camera.pos.x = list->u_data.camera.pos.x;
		new_node->u_data.camera.pos.y = list->u_data.camera.pos.y; 
		new_node->u_data.camera.pos.z = list->u_data.camera.pos.z;
		new_node->u_data.camera.orient.x = list->u_data.camera.orient.x;
		new_node->u_data.camera.orient.y = list->u_data.camera.orient.y; 
		new_node->u_data.camera.orient.z = list->u_data.camera.orient.z;
		new_node->u_data.camera.up.x = list->u_data.camera.up.x;
		new_node->u_data.camera.up.y = list->u_data.camera.up.y; 
		new_node->u_data.camera.up.z = list->u_data.camera.up.z;
		new_node->u_data.camera.right.x = list->u_data.camera.right.x;
		new_node->u_data.camera.right.y = list->u_data.camera.right.y; 
		new_node->u_data.camera.right.z = list->u_data.camera.right.z;
		new_node->u_data.camera.fov = list->u_data.camera.fov;
	}
	else if (new_node->type == LIGHT)
	{
		new_node->u_data.light.pos.x = list->u_data.light.pos.x;
		new_node->u_data.light.pos.y = list->u_data.light.pos.y;
		new_node->u_data.light.pos.z = list->u_data.light.pos.z;
		new_node->u_data.light.colors.x = list->u_data.light.colors.x;
		new_node->u_data.light.colors.y = list->u_data.light.colors.y;
		new_node->u_data.light.colors.z = list->u_data.light.colors.z;
		new_node->u_data.light.light_ratio = list->u_data.light.light_ratio;
	}
	else if (new_node->type == SPHERE)
	{
		new_node->u_data.sphere.center.x = list->u_data.sphere.center.x;
		new_node->u_data.sphere.center.y = list->u_data.sphere.center.y;
		new_node->u_data.sphere.center.z = list->u_data.sphere.center.z;
		new_node->u_data.sphere.radius = list->u_data.sphere.radius;
		new_node->u_data.sphere.colors.x = list->u_data.sphere.colors.x;
		new_node->u_data.sphere.colors.y = list->u_data.sphere.colors.y;
		new_node->u_data.sphere.colors.z = list->u_data.sphere.colors.z;
		
		new_node->u_data.sphere.xpm.img = list->u_data.sphere.xpm.img;
		new_node->u_data.sphere.xpm.addr = list->u_data.sphere.xpm.addr;
		new_node->u_data.sphere.xpm.bits_per_pixel = list->u_data.sphere.xpm.bits_per_pixel;
		new_node->u_data.sphere.xpm.line_length = list->u_data.sphere.xpm.line_length;
		new_node->u_data.sphere.xpm.endian = list->u_data.sphere.xpm.endian;
		new_node->u_data.sphere.xpm.wdth = list->u_data.sphere.xpm.wdth;
		new_node->u_data.sphere.xpm.hgt = list->u_data.sphere.xpm.hgt;

		new_node->u_data.sphere.n_map.img = list->u_data.sphere.n_map.img;
		new_node->u_data.sphere.n_map.addr = list->u_data.sphere.n_map.addr;
		new_node->u_data.sphere.n_map.bits_per_pixel = list->u_data.sphere.n_map.bits_per_pixel;
		new_node->u_data.sphere.n_map.line_length = list->u_data.sphere.n_map.line_length;
		new_node->u_data.sphere.n_map.endian = list->u_data.sphere.n_map.endian;
		new_node->u_data.sphere.n_map.wdth = list->u_data.sphere.n_map.wdth;
		new_node->u_data.sphere.n_map.hgt = list->u_data.sphere.n_map.hgt;

		new_node->u_data.sphere.flg = list->u_data.sphere.flg;
	}
	else if (new_node->type == PLANE)
	{
		new_node->u_data.plane.point.x = list->u_data.plane.point.x;
		new_node->u_data.plane.point.y = list->u_data.plane.point.y;
		new_node->u_data.plane.point.z = list->u_data.plane.point.z;
		new_node->u_data.plane.orient.x = list->u_data.plane.orient.x;
		new_node->u_data.plane.orient.y = list->u_data.plane.orient.y;
		new_node->u_data.plane.orient.z = list->u_data.plane.orient.z;
		new_node->u_data.plane.colors.x = list->u_data.plane.colors.x;
		new_node->u_data.plane.colors.y = list->u_data.plane.colors.y;
		new_node->u_data.plane.colors.z = list->u_data.plane.colors.z;
	}
	else if (new_node->type == CYLINDER)
	{
		new_node->u_data.cylinder.center.x = list->u_data.cylinder.center.x;
		new_node->u_data.cylinder.center.y = list->u_data.cylinder.center.y;
		new_node->u_data.cylinder.center.z = list->u_data.cylinder.center.z;
		new_node->u_data.cylinder.orient.x = list->u_data.cylinder.orient.x;
		new_node->u_data.cylinder.orient.y = list->u_data.cylinder.orient.y;
		new_node->u_data.cylinder.orient.z = list->u_data.cylinder.orient.z;
		new_node->u_data.cylinder.colors.x = list->u_data.cylinder.colors.x;
		new_node->u_data.cylinder.colors.y = list->u_data.cylinder.colors.y;
		new_node->u_data.cylinder.colors.z = list->u_data.cylinder.colors.z;
		new_node->u_data.cylinder.radius = list->u_data.cylinder.radius;
		new_node->u_data.cylinder.hgt = list->u_data.cylinder.hgt;

		new_node->u_data.cylinder.xpm.img = list->u_data.cylinder.xpm.img;
		new_node->u_data.cylinder.xpm.addr = list->u_data.cylinder.xpm.addr;
		new_node->u_data.cylinder.xpm.bits_per_pixel = list->u_data.cylinder.xpm.bits_per_pixel;
		new_node->u_data.cylinder.xpm.line_length = list->u_data.cylinder.xpm.line_length;
		new_node->u_data.cylinder.xpm.endian = list->u_data.cylinder.xpm.endian;
		new_node->u_data.cylinder.xpm.wdth = list->u_data.cylinder.xpm.wdth;
		new_node->u_data.cylinder.xpm.hgt = list->u_data.cylinder.xpm.hgt;

		new_node->u_data.cylinder.n_map.img = list->u_data.cylinder.n_map.img;
		new_node->u_data.cylinder.n_map.addr = list->u_data.cylinder.n_map.addr;
		new_node->u_data.cylinder.n_map.bits_per_pixel = list->u_data.cylinder.n_map.bits_per_pixel;
		new_node->u_data.cylinder.n_map.line_length = list->u_data.cylinder.n_map.line_length;
		new_node->u_data.cylinder.n_map.endian = list->u_data.cylinder.n_map.endian;
		new_node->u_data.cylinder.n_map.wdth = list->u_data.cylinder.n_map.wdth;
		new_node->u_data.cylinder.n_map.hgt = list->u_data.cylinder.n_map.hgt;
	}
	else if (new_node->type == HYPERBOLOID)
	{
		new_node->u_data.hyperboloid.center.x = list->u_data.hyperboloid.center.x;
		new_node->u_data.hyperboloid.center.y = list->u_data.hyperboloid.center.y;
		new_node->u_data.hyperboloid.center.z = list->u_data.hyperboloid.center.z;
		new_node->u_data.hyperboloid.orient.x = list->u_data.hyperboloid.orient.x;
		new_node->u_data.hyperboloid.orient.y = list->u_data.hyperboloid.orient.y;
		new_node->u_data.hyperboloid.orient.z = list->u_data.hyperboloid.orient.z;
		new_node->u_data.hyperboloid.colors.x = list->u_data.hyperboloid.colors.x;
		new_node->u_data.hyperboloid.colors.y = list->u_data.hyperboloid.colors.y;
		new_node->u_data.hyperboloid.colors.z = list->u_data.hyperboloid.colors.z;
		new_node->u_data.hyperboloid.radius = list->u_data.hyperboloid.radius;
		new_node->u_data.hyperboloid.hgt = list->u_data.hyperboloid.hgt;
	}
	return (new_node);
}



void	init_thread_data(t_data *th_d, t_data *d)
{
	init_minirt_data(th_d);
	th_d->chaos = copy_obj_list_deep(d->chaos);
	th_d->count.sp_count = d->count.sp_count;
	th_d->count.pl_count = d->count.pl_count;
	th_d->count.cy_count = d->count.cy_count;
	th_d->count.l_count = d->count.l_count;
	th_d->count.hy_count = d->count.hy_count;
	obj_array_create(th_d);
	initialise_viewport(th_d);
}
