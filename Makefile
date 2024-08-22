SRCS = cub3d.c ./parssing/parssing.c ./sources/get_next_line/get_next_line.c
OBJS = ${SRCS:.c=.o}
NAME = cub3d
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DIR = sources/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)  

all: ${NAME}

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@${RM} ${OBJS}
	@$(MAKE) -C $(LIBFT_DIR) clean  # Clean in the libft directory

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C $(LIBFT_DIR) fclean  # Full clean in the libft directory

re: fclean all

.PHONY : clean
