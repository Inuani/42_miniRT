#include "../../includes/minirt.h"

void	create_obj_tok(t_data *d, char *line, int *i)
{
	char	*obj;
	int		j;
	t_tok	*new;
	j = *i;
	while (line[*i] && ft_isalpha(line[*i]))
		*i += 1;
	obj = ft_substr(line, j, *i - j);
	if (!obj)
		exit_error(ERR_MALLOC, 260);
	new = tok_lstnew(obj, 0);
	if (!new)
		exit_error(ERR_MALLOC, 260);
	tok_add_back(&d->lst, new);
}

void	create_prop_tok(t_data *d, char *line, int *i)
{
	char	*prop;
	int		j;
	t_tok	*new;

	j = *i;
	while (line[*i] && (ft_isdigit(line[*i]) || line[*i] == '.' || line[*i] == '-'))
		*i += 1;
	prop = ft_substr(line, j, *i - j);
	if (!prop)
		exit_error(ERR_MALLOC, 260);
	new = tok_lstnew(prop, 1);
	if (!new)
		exit_error(ERR_MALLOC, 260);
	tok_add_back(&d->lst, new);
}

void	parse_line(char *line, t_data *d)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
			if (line[i] && is_space(line[i]))
				skip_space(line, &i);
			else if (line[i] && ft_isalpha(line[i]))
				create_obj_tok(d, line, &i);
			else if (line[i] && (ft_isdigit(line[i]) || line[i] == '-'))
				create_prop_tok(d, line, &i);
			else if (line[i] && line[i] == ',')
				i++;
			else
				exit_error(ERR_FILE, 1);
	}
	// print_token(&d->lst);
	obj_eman(d);
}

void	read_rt_file(char **av, t_data *d)
{
	int			fd;
	char		*line;
	(void)d;
	fd = open(av[1], O_RDONLY);
	if  (fd == -1)
		exit_error(ERR_OPEN, 1);
	line = get_next_line(fd);
	parse_line(line, d);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		parse_line(line, d);
	}
	free(line);
	if (close(fd) < 0)
		exit_error(ERR_CLOSE, 1);
}

void	init_minirt_data(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
	d->vp = NULL;
	d->lst = NULL;
	d->count.total = 0;
	d->count.l_count = 0;
	d->count.sp_count = 0;
	d->count.pl_count = 0;
	d->count.cy_count = 0;
	d->count.hy_count = 0;
	d->chaos = NULL;
	d->objs = NULL;
}

void	mrt_parsing(char **av, t_data *d)
{
	init_minirt_data(d);
	read_rt_file(av, d);
	obj_array_create(d);
}


