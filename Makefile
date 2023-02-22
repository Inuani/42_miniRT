NAME = miniRT

CC = gcc

RM = rm -f

# Directories
OBJ_DIR = objs/
INC_DIR = includes/
SRC_DIR = src/

# Libraries
LIBFT  = libs/libft/

CFLAGS = -Wall -Wextra -Werror
FSANI = -fsanitize=address -g3

SRC =	main.c \

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

debug:
	$(CC) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C libft

fclean:
	$(RM) $(NAME)
	$(MAKE) fclean -C libft


re: fclean all

.PHONY: fclean clean re all