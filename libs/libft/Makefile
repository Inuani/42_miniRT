# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egauthey <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 08:23:28 by egauthey          #+#    #+#              #
#    Updated: 2022/10/21 12:39:15 by egauthey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

LIB = ar rcs

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
  	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_split.c \
	   ./src_printf/ft_printf.c \
	  ./src_printf/fputstr.c \
	  ./src_printf/fputchar.c \
	  ./src_printf/fputnbrbase.c \
	  ./src_printf/fputptr.c \
	  ./src_printf/fputint.c \
	  ./src_get_next_line/get_next_line.c \
	  ./src_get_next_line/get_next_line_utils.c \
	  ./src_get_next_line/get_next_line_bonus.c \
	  ./src_get_next_line/get_next_line_utils_bonus.c

SRCS_BONUS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	$(LIB) $(NAME) $(OBJS) $(OBJS_BONUS)
	
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
