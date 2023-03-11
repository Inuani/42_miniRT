#include "../../includes/minirt.h"

int	is_space(int c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

void	skip_space(char *line, int *i)
{
	while(line[*i] && is_space(line[*i]))
		*i += 1;
}

float	ft_atof(const char *str)
{
	float	nb;
	float	neg;
	float	div;

	nb = 0.0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		nb = nb * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		div = 10;
		while (*str && ft_isdigit(*str))
		{
			nb = nb + (*str++ - '0') / div;
			div *= 10; 
		}
	}
	return (nb * neg);
}

int	calc_nb_prop(t_tok *lst)
{
	t_tok	*tmp;
	int		nb;

	nb = 0;
	tmp = lst;
	while(tmp)
	{
		if (tmp->type == 1 || tmp->type == 2)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	set_xpm_path(char **n_img, char **n_path, char **xpm, char **img)
{
	*n_path = ft_strjoin("images/", "n_");
	if (!*n_path)
		exit_error(ERR_MALLOC, 260);
	*n_img = ft_strjoin(*n_path, *img);
	if (!n_img)
		exit_error(ERR_MALLOC, 260);
	*xpm = ft_strjoin("images/", *img);
	if (!xpm)
		exit_error(ERR_MALLOC, 260);
	if (access(*xpm, F_OK) != 0)
		exit_error(ERR_XPM_IMG, 1);
	if (access(*n_img, F_OK) != 0)
		exit_error(ERR_XPM_IMG, 1);
}

