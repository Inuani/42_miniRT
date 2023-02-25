#ifndef PARSING_H
# define PARSING_H

// ----------------------------------------------
// mrt_parsing.c
// ----------------------------------------------

int	mrt_parsing(char **av);

// ----------------------------------------------
// errors.c
// ----------------------------------------------

int	mrt_error(char *msg, int error);

# define ERR_OPEN "Open error "

#endif
