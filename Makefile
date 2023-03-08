NAME = miniRT

CC = gcc

RM = rm -f

# Directories
OBJ_DIR = objs/
SRC_DIR = src/
PARS_DIR = parsing/
SHAPE_DIR = shape/
VEC_DIR = vector/
THDS_DIR = threads/
REND_DIR = render/
RAY_DIR = ray/

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

SHAPE_SRC = $(addprefix $(SHAPE_DIR),	plane.c \
										cylinder.c \
										hyperboloid.c \
										sphere.c \
										)

VEC_SRC = $(addprefix $(VEC_DIR),	vec_utils.c \
									vec_utils2.c \
									)

THDS_SRC = $(addprefix $(THDS_DIR),	threads.c \
									)

REND_SRC = $(addprefix $(REND_DIR),	render.c \
									handle_window.c \
									handle_keys.c \
									trgb.c \
									)

RAY_SRC = $(addprefix $(RAY_DIR),	rays.c \
									hit_objs.c \
									)

SRC =	main.c \
		init_objs.c \
		rand.c \
		debug.c \

OBJ := $(SRC:%.c=%.o)
PARS_OBJ := $(PARS_SRC:%.c=%.o)
SHAPE_OBJ := $(SHAPE_SRC:%.c=%.o)
VEC_OBJ := $(VEC_SRC:%.c=%.o)
THDS_OBJ := $(THDS_SRC:%.c=%.o)
REND_OBJ := $(REND_SRC:%.c=%.o)
RAY_OBJ := $(RAY_SRC:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC) $(PARS_SRC) $(SHAPE_SRC) $(VEC_SRC) $(THDS_SRC) $(REND_SRC) $(RAY_SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ) $(PARS_OBJ) $(SHAPE_OBJ) $(VEC_OBJ) $(THDS_OBJ) $(REND_OBJ) $(RAY_OBJ))

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
	@mkdir $(OBJ_DIR)/$(SHAPE_DIR)
	@mkdir $(OBJ_DIR)/$(VEC_DIR)
	@mkdir $(OBJ_DIR)/$(THDS_DIR)
	@mkdir $(OBJ_DIR)/$(REND_DIR)
	@mkdir $(OBJ_DIR)/$(RAY_DIR)

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