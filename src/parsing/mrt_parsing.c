#include "../../includes/minirt.h"

void	create_obj_tok(t_tok **lst, char *line, int *i)
{
	char	*obj;
	int		j;
	t_tok	*new;

	j = *i;
	while (line[*i] && ft_isalpha(line[*i]))
		*i += 1;
	obj = ft_substr(line, j, *i - j);
	new = tok_lstnew(obj, 0);
	tok_add_back(lst, new);
}

void	create_attrib_tok(t_tok **lst, char *line, int *i)
{
	char	*attrib;
	int		j;
	t_tok	*new;

	j = *i;
	while (line[*i] && (ft_isdigit(line[*i]) || line[*i] == '.' || line[*i] == '-'))
		*i += 1;
	attrib = ft_substr(line, j, *i - j);
	new = tok_lstnew(attrib, 1);
	tok_add_back(lst, new);
}

void	parse_line(char *line, t_data *d)
{
	int		i;
	t_tok	*lst;

	i = 0;
	lst = NULL;
	while (line && line[i])
	{
			if (line[i] && is_space(line[i]))
				skip_space(line, &i);
			else if (line[i] && ft_isalpha(line[i]))
				create_obj_tok(&lst, line, &i);
			else if (line[i] && (ft_isdigit(line[i]) || line[i] == '-'))
				create_attrib_tok(&lst, line, &i);
			else
				i++;
	}
	print_token(&lst);
	(void)d;
	// create object

	// add to tableau of object in d
	// printf("%s\n", line);

}

int	mrt_parsing(char **av, t_data *d)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if  (fd == -1)
		return (mrt_error(ERR_OPEN, 1));
	line = get_next_line(fd);
	parse_line(line, d);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		parse_line(line, d);
	}
	free(line);
	close(fd);
	return (0);
}
