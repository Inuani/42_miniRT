#include "../../includes/minirt.h"

t_object	*create_object(t_type type, void *data)
{
	t_object	*new;
	
	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	if (type == LIGHT)
		new->u_data.light = *(t_light*)data;
	else if (type == SPHERE)
		new->u_data.sphere = *(t_sphere*)data;
	else if (type == PLANE)
		new->u_data.plane = *(t_plane*)data;
	else if (type == CYLINDER)
		new->u_data.cylinder = *(t_cylinder*)data;
	new->next = NULL;
	return (new);
}

void	add_object_to_list(t_object **lst, t_object *new)
{
	t_object	*last;

	last = get_last_object(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}

t_object	*get_last_object(t_object *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	nb_objects(t_object *lst)
{
	t_object	*tmp;
	int			i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}