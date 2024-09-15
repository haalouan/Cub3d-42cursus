SRCS = cub3d.c ./parssing/parssing.c ./sources/get_next_line/get_next_line.c ./parssing/textures.c \
	./parssing/check.c ./parssing/allocation.c ./parssing/parssing_utils.c ./parssing/parsse_map.c
OBJS = ${SRCS:.c=.o}
NAME = cub3d
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DIR = sources/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Cub3d is ready"

all: ${NAME}

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@${RM} ${OBJS}
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Cub3d is cleaned"
	@echo "Libft is cleaned"

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY : clean
