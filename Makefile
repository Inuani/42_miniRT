NAME = miniRT

CC = gcc

RM = rm -rf

# Directories
OBJ_DIR = objs/
SRC_DIR = src/

# Libraries
LIBFT  = -I.libs/libft/

# includes
INC = -I.includes/

LIBFLAGS = -Llibs/libft -lft -Llibs/mlx -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror
FSANI = -fsanitize=address -g3

SRC =	main.c \
		handle_window.c \
		handle_keys.c \

OBJ := $(SRC:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	$(MAKE) -C libs/libft
	${MAKE} -C libs/mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $< -c -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

debug:
	$(CC) $(CFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C libs/libft
	${MAKE} clean -C libs/mlx

fclean:
	$(RM) $(NAME)
	$(MAKE) fclean -C libs/libft
	${MAKE} clean -C libs/mlx

re: fclean all

.PHONY: fclean clean re all