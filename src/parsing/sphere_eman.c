#include "../../includes/minirt.h"

void	get_sphere(t_data *d)
{
	t_object	*tmp;
	int	i;

	i = 2 + d->count.l_count;
	tmp = d->chaos;
	while(tmp)
	{
		if (tmp->type == SPHERE)
		{
			d->objs[i] = tmp;
			i++;
		}
		tmp = tmp->next;
	}
}

void	sp_img_init(t_data *d, t_tok **lst, t_sphere *cur)
{
	char	*n_img;
	char	*n_path;
	char	*xpm;

	n_img = NULL;
	n_path = NULL;
	xpm = NULL;
	*lst = (*lst)->next;
	set_xpm_path(&n_img, &n_path, &xpm, &(*lst)->s);
	cur->xpm.img = mlx_xpm_file_to_image(d->mlx, xpm, &cur->xpm.wdth, &cur->xpm.hgt);
	cur->xpm.addr = mlx_get_data_addr(cur->xpm.img, &cur->xpm.bits_per_pixel, &cur->xpm.line_length, &cur->xpm.endian);
	cur->n_map.img = mlx_xpm_file_to_image(d->mlx, n_img, &cur->n_map.wdth, &cur->n_map.hgt);
	cur->n_map.addr = mlx_get_data_addr(cur->n_map.img, &cur->n_map.bits_per_pixel, &cur->n_map.line_length, &cur->n_map.endian);
	free(n_path);
	free(n_img);
	free(xpm);
}

void	set_sp_prop(t_tok **lst, t_sphere *inst)
{
	*lst = (*lst)->next;
	inst->center.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->center.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->center.z = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->radius = (ft_atof((*lst)->s) / 2.0);
	*lst = (*lst)->next;
	inst->colors.x = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.y = ft_atof((*lst)->s);
	*lst = (*lst)->next;
	inst->colors.z = ft_atof((*lst)->s);
	inst->up = (t_vec) {0, 1, 0};
	inst->right = (t_vec) {1, 0, 0};
}

int	add_sphere(t_data *d, t_tok *lst)
{
	t_object	*new;
	t_sphere	inst;
	int			nb;

	nb = calc_nb_prop(lst);
	if (nb != 7 && nb != 8)
		exit_error(ERR_PROPERTIES, 1);
	inst.flg = 0;
	set_sp_prop(&lst, &inst);
	if (nb == 8)
	{
		if (!ft_strncmp(lst->next->s, "damier", 6))
			inst.flg = 1;
		else
		{
			sp_img_init(d, &lst, &inst);
			inst.flg = 2;
		}
	}
	new = create_object(SPHERE, &inst);
	add_object_to_list(&d->chaos, new);
	free_tok(d);
	return (1);
}