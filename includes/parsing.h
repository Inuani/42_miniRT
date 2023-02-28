#ifndef PARSING_H
# define PARSING_H



// ----------------------------------------------
// mrt_parsing.c
// ----------------------------------------------

void	mrt_parsing(char **av, t_data *d);

// ----------------------------------------------
// obj_emanation.c
// ----------------------------------------------

void	what_obj(t_data *d, char *obj);
void	obj_eman(t_data *d);

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
int		tok_lst_size(t_tok *lst);
t_tok	*remove_tok(t_tok **lst, t_tok *tok_to_remove);

// ----------------------------------------------
// obj_array_creation.c
// ----------------------------------------------

void	obj_array_create(t_data *d);

// ----------------------------------------------
// errors.c
// ----------------------------------------------

int		mrt_error(char *msg, int error);
void	exit_error(char *msg, int error);
void	free_tok_from_end(t_data *d);

// ----------------------------------------------
// pars_debug.c
// ----------------------------------------------


void	print_token(t_tok **lst);
void	print_object(t_object obj);

# define ERR_OPEN "Open error "
# define ERR_CLOSE "Close error "
# define ERR_FILE "Error : file corrupted."
# define ERR_MALLOC "Error : memory allocation."
# define ERR_OBJ "Error : object included does not exist."
# define ERR_PROPERTIES "Error : incorrect properties of an object"

#endif
