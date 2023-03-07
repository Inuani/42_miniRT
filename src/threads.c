
#include "../includes/minirt.h"

//WIDTH / 6;
//HEIGH / 4;


void	create_thread(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->lock, 0);
	data->thread_id = malloc(sizeof(pthread_t) * THREADS);
	i = 0;
	while (i < THREADS)
	{
		data->thread_i = i;
		pthread_create(&data->thread_id[i], NULL, render_thr, data);
		usleep(1000);
		i++;
	}
	i = 0;
	//while (i < 12)
	//	pthread_join(data->thread_id[i], NULL);
}

t_object* copy_list_deep(const t_object *list)
{
	if (list == NULL) {
		return NULL;
	}

	t_object* new_node = malloc(sizeof(t_object));
	new_node->type = list->type;
	if (list->next != NULL)
		new_node->next = copy_list_deep(list->next);

	if (new_node->type == AMBIANT)
	{
		
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
	}
	else if (new_node->type == LIGHT)
	{
		
	}
	else if (new_node->type == SPHERE)
	{
		
	}
	else if (new_node->type == PLANE)
	{
		
	}
	else if (new_node->type == CYLINDER)
	{
		
	}
	return new_node;
}
