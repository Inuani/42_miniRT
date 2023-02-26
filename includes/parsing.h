#ifndef PARSING_H
# define PARSING_H

// ----------------------------------------------
// mrt_parsing.c
// ----------------------------------------------

int	mrt_parsing(char **av);

// ----------------------------------------------
// parsing_utils.c
// ----------------------------------------------

int		is_space(int c);
void	skip_space(char *line, int *i);

// ----------------------------------------------
// errors.c
// ----------------------------------------------

int	mrt_error(char *msg, int error);

# define ERR_OPEN "Open error "

#endif
