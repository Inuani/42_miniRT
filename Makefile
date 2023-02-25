NAME = miniRT

CC = gcc

RM = rm -f

# Directories
OBJ_DIR = objs/
SRC_DIR = src/

# Libraries
LIBFT  = libs/libft
MLX = libs/mlx

# includes
INC = -I.includes/

LIBFLAGS = -Llibs/libft -lft -Llibs/mlx -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror
FSANI = -fsanitize=address -g3

SRC =	main.c \
		handle_window.c \
		handle_keys.c \
		rays.c \
		render.c \
		trgb.c \
		vec_utils.c \
		init_objs.c \
		sphere.c	\
		rand.c


OBJ := $(SRC:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	$(MAKE) -C libs/libft
	${MAKE} -C libs/mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -I.$(LIBFT) $< -c -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

debug:
	$(CC) $(CFLAGS)

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