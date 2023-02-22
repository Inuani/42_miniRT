NAME = miniRT

CC = gcc

RM = rm -f

# Directories
OBJ_DIR = objs/

SRC_DIR = src/

# Libraries
LIBFT  = -I.libs/libft/

# includes
INC = -I.includes/

LIBFLAGS = -Llibft -lft -L. -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror
FSANI = -fsanitize=address -g3

SRC =	main.c \

OBJ := $(SRC:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(SRCS) $(OBJ_DIR) $(OBJS)
	$(MAKE) -C libft
	${MAKE} -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $< -c -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

debug:
	$(CC) $(CFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)
	$(MAKE) clean -C libft
	${MAKE} clean -C mlx

fclean:
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: fclean clean re all