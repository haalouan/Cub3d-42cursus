SRCS = cub3d.c ./parssing/parssing.c ./sources/get_next_line/get_next_line.c ./parssing/parssTextures.c \
	./parssing/check.c ./parssing/allocation.c ./parssing/parssUtils.c ./parssing/parssMap.c ./parssing/parssText.c\
	./parssing/free.c execution/render/texture.c ./execution/free_resources.c\
	execution/player/mouvements.c execution/player/player.c execution/render/render.c execution/render/hooks.c  \
 	execution/raycasting/drawing_algorithms.c execution/render/walls.c execution/render/rays.c execution/init.c \
	execution/raycasting/horizontal_calc.c execution/map/miniMap.c execution/render/line.c execution/raycasting/vertical_calc.c execution/map/map.c 
MLX_LIB = MLX42/build/libmlx42.a 
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
OBJS = ${SRCS:.c=.o}
NAME = cub3d
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DIR = sources/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ${MLX_FLAGS} ${MLX_LIB} -Iinclude -lglfw -L"/Users/shamdoun/.brew/opt/glfw/lib/" -o $(NAME)
	@echo "Cub3d is ready"

all: ${NAME}

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c cub3d.h
	@$(CC) $(CFLAGS) -g -Iinclude -c $< -o $@

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
