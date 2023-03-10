#ifndef PARSING_H
# define PARSING_H


// ----------------------------------------------
// mrt_parsing.c
// ----------------------------------------------

void	mrt_parsing(char **av, t_data *d);
void	init_minirt_data(t_data *d);

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
// object_list_utils.c
// ----------------------------------------------

t_object	*create_object(t_type type, void *data);
void		add_object_to_list(t_object **lst, t_object *new);
t_object	*get_last_object(t_object *lst);
int			nb_objects(t_object *lst);

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

void	exit_error(char *msg, int error);
// void	free_tok_from_end(t_tok *lst);
void	free_tok(t_data *d);
void	free_obj_list(t_object *head);

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
# define ERR_XPM_IMG "Error : incorrect xpm file"

#endif
