NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

OBJ_DIR = ./obj/
SRC_DIR = ./src/
INC_DIR = ./include/
LIBFT = ./libft/
MLX = ./minilibx-linux/

SRCS = dda.c ft_checker.c ft_free.c ft_init.c ft_init_1.c keys.c minimap.c mlx_utils.c raycaster.c texture.c \
       ft_checker_1.c ft_checkerdata.c ft_get_rgb.c ft_utils.c ft_utils_1.c main.c mlx_line.c player_move.c \
       scenes.c vector_utils.c ft_parse_utils.c fps.c 

SRC_FILES = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

IFLAGS = -I$(INC_DIR) -I$(LIBFT) -I$(MLX)
LFLAGS = -L$(LIBFT) -lft -L$(MLX) -lmlx -lXext -lX11 -lm

all: $(NAME)

bonus: all

$(NAME): $(OBJ_DIR) $(OBJ)
	$(MAKE) bonus -C $(LIBFT) --no-print-directory
	@if [ ! -f $(MLX)/libmlx.a ]; then $(MAKE) -C $(MLX) --no-print-directory; fi
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(CFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT) --no-print-directory
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT) --no-print-directory
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

