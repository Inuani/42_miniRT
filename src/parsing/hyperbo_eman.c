#include "../../includes/minirt.h"

void	get_hyperboloid(t_data *d)
{
	t_object	*tmp;
	int	i;

	tmp = d->chaos;
	i = 2 + d->count.l_count + d->count.sp_count + d->count.pl_count + d->count.cy_count;
	while(tmp)
	{
		if (tmp->type == HYPERBOLOID)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	set_hp_prop(t_tok **lst, t_hyperboloid *inst)
{
	*lst = (*lst)->next;
	inst->center.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->center.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->center.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->orient.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->radius = (ft_atof((*lst)->s) / 2.0);
	*lst = (*lst)->next;
	inst->hgt = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.z = ft_atof((*lst)->s);
	inst->orient = vec_unit(inst->orient);
}

int	add_hyperboloid(t_data *d, t_tok *lst)
{
	t_object		*new;
	t_hyperboloid	inst;
	int				nb;

	nb = calc_nb_prop(lst);
	if (nb != 11)
		exit_error(ERR_PROPERTIES, 1);
	set_hp_prop(&lst, &inst);
	new = create_object(HYPERBOLOID, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
	return (1);
}