SRCS =	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_strtrim.c ft_memcpy.c ft_atoi.c ft_substr.c

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBC = ar rcs
RM = rm -f
OBJ = $(SRCS:.c=.o)

$(NAME):$(OBJ)
		@echo "Libft is ready"
		@$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

%.o:    %.c libft.h
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean