#include "../../includes/minirt.h"

int	calc_nb_prop(t_tok *lst)
{
	t_tok	*tmp;
	int		nb;

	nb = 0;
	tmp = lst;
	while(tmp)
	{
		if (tmp->type == 1)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	add_ambiant(t_data *d, t_tok *lst)
{
	t_object	*new
	t_ambiant	*inst;
	int	nb;

	nb = calc_nb_attrib(lst);
	if (nb != 4)
		exit_error(ERR_PROPERTIES, 1)
	remove_tok(&lst, lst);
	inst->light_ratio = ft_atof(lst->s);
	remove_tok(&lst, lst);
	inst->colors->x = ft_atof(lst->s);
	remove_tok(&lst, lst);
	inst->colors->y = ft_atof(lst->s);
	remove_tok(&lst, lst);
	inst->colors->z = ft_atof(lst->s);
	remove_tok(&lst, lst);

	new = create_object(AMBIANT, inst);
	add_object_to_list(&d->chaos, new)
}




void	what_obj(, t_data *d, t_tok *lst, char *obj)
{
	if (!ft_strncmp(obj, "A", 1) && obj[1] == 0)
		add_ambiant(d, lst);
	else if (!ft_strncmp(obj, "C", 1) && obj[1] == 0)
		add_camera(d, lst);
	else if (!ft_strncmp(obj, "L", 1) && obj[1] == 0)
		add_light(d, lst);
	else if (!ft_strncmp(obj, "sp", 2) && obj[2] == 0)
		add_sphere(d, lst);
	else if (!ft_strncmp(obj, "pl", 2) && obj[2] == 0)
		add_plane(d, lst);
	else if (!ft_strncmp(obj, "cy", 2) && obj[2] == 0)
		add_cylinder(d, lst);
	else
		exit_error(ERR_OBJ, 1)
}


{
	t_tok	*tmp;

	tmp = lst;
	while(tmp)
	{
		if (tmp->type == 0)
			what_obj(lst, tmp->s)
		tmp = tmp->next;
	}
}
void	obj_eman(t_tok *lst, t_data *d)
{
	t_object	*new;
	int			nb_obj;
	(void)d;

	// what_obj
	new = create_object(t_type type, void *data)
	add_object_to_list(t_object **lst, t_object *new)
}

// NOT NEEDED YET
int	calc_nb_attrib(t_tok *lst)
{
	t_tok	*tmp;
	int		nb;

	nb = 0;
	tmp = lst;
	while(tmp)
	{
		if (tmp->type == 1)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}