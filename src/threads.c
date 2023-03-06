
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