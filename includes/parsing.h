#ifndef PARSING_H
# define PARSING_H

typedef struct s_tok {
	int				type;
	char			*s;
	struct s_tok	*next;
	struct s_tok	*prev;
}				t_tok;

// ----------------------------------------------
// mrt_parsing.c
// ----------------------------------------------

int	mrt_parsing(char **av, t_data *d);

// ----------------------------------------------
// parsing_utils.c
// ----------------------------------------------

int		is_space(int c);
void	skip_space(char *line, int *i);
float	ft_atof(const char *str);

// ----------------------------------------------
// tok_list_utils.c
// ----------------------------------------------

t_tok	*tok_lstnew(char *s, int t);
void	tok_add_back(t_tok **lst, t_tok *new);
t_tok	*tok_last(t_tok *lst);
int	tok_lst_size(t_tok *lst);


// ----------------------------------------------
// errors.c
// ----------------------------------------------

int	mrt_error(char *msg, int error);

// ----------------------------------------------
// pars_debug.c
// ----------------------------------------------

void	print_token(t_tok **lst);

# define ERR_OPEN "Open error "

#endif
