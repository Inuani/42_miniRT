
#include "../includes/minirt.h"

void	printf_vec(t_vec vec)
{
	printf("x : %f\n", vec.x);
	printf("y : %f\n", vec.y);
	printf("z : %f\n", vec.z);
	printf("\n");
}

int	print_key(int key, t_data *data)
{
	(void)data;
	printf("key : %i\n", key);
	return (0);
}

void	print_new_list(t_data *d)
{
	t_object	*tmp;
	t_object	*new_chaos;

	tmp = d->chaos;
	new_chaos = copy_obj_list_deep(tmp);

	printf("new objs list:\n\n");
	while (new_chaos)
	{
		print_object(*new_chaos);
		new_chaos = new_chaos->next;
	}
}