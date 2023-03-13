/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:51:04 by egauthey          #+#    #+#             */
/*   Updated: 2022/11/21 18:51:06 by egauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	parse_line(char *line, t_data *d)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] && is_space(line[i]))
			skip_space(line, &i);
		else if (line[i] && ft_isalpha(line[i]) && line[i + 1] && line[i + 2]
			&& (is_space(line[i + 1]) || is_space(line[i + 2])))
			create_obj_tok(d, line, &i);
		else if (line[i] && (ft_isdigit(line[i]) || line[i] == '-'))
			create_prop_tok(d, line, &i);
		else if (line[i] && ft_isalpha(line[i]))
			create_xpm_tok(d, line, &i);
		else if (line[i] && line[i] == ',')
			i++;
		else
			exit_error(ERR_FILE, 1);
	}
	obj_eman(d);
}

void	read_rt_file(char **av, t_data *d)
{
	int		fd;
	char	*line;
	if (!ft_strncmp(av[1], "scenes", 7) || !ft_strncmp(av[1], "scenes/", 8))
		exit_error("miniRT error ", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_error(ERR_OPEN, 1);
	printf("fd : %d", fd);
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

void	initialise_viewport(t_data *data)
{
	t_cam	cam;

	cam = data->objs[1]->u_data.camera;
	data->vp = malloc(sizeof(t_viewport) + 1);
	data->vp->aspect_ratio = 16.0 / 9.0;
	data->vp->viewp_wdt = tan(cam.fov / 2 * M_PI / 180.0) * 2;
	data->vp->viewp_hgt = data->vp->viewp_wdt / (data->vp->aspect_ratio);
	data->vp->focal_len = 1;
	data->vp->samplespp = 100;
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
	init_window(d);
	init_image(d, WIDTH, HEIGHT, &d->img);
	read_rt_file(av, d);
	obj_array_create(d);
	initialise_viewport(d);
}
