NAME = miniRT

CC = gcc

RM = rm -f

# Directories
OBJ_DIR = objs/
SRC_DIR = src/
PARS_DIR = parsing/

# Libraries
LIBFT  = libs/libft
MLX = libs/mlx

# includes
INC = -I.includes/

LIBFLAGS = -Llibs/libft -lft -Llibs/mlx -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror
FSANI = -fsanitize=address -g3

PARS_SRC = $(addprefix $(PARS_DIR),	mrt_parsing.c \
									parsing_utils.c \
									errors.c \
									obj_list_utils.c \
									pars_debug.c \
									tok_list_utils.c \
									obj_emanation.c \
									obj_array_creation.c \
									)

SRC =	main.c \
		handle_window.c \
		handle_keys.c \
		rays.c \
		render.c \
		trgb.c \
		vec_utils.c \
		init_objs.c \
		sphere.c \
		rand.c \
		plane.c \
		hit_objs.c \
		cylinder.c \
		threads.c \
		hyperboloid.c

OBJ := $(SRC:%.c=%.o)
PARS_OBJ := $(PARS_SRC:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC) $(PARS_SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ) $(PARS_OBJ))

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	$(MAKE) -C $(LIBFT)
	${MAKE} -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I.$(LIBFT) $(INC)  $< -c -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)/$(PARS_DIR)

debug: $(SRCS) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(FSANI) $(OBJS) $(LIBFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(MLX) 
	${MAKE} clean -C $(LIBFT)

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
	rm -rf $(OBJ_DIR)
	$(MAKE) fclean -C $(LIBFT)
	${MAKE} clean -C $(MLX)

re: fclean all

.PHONY: fclean clean re all