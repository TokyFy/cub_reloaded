NAME 			= cub3D
BONUS			= cub3D_bonus
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM 				= rm -f

OBJ_DIR 		= ./obj/
OBJ_DIR_BONUS	= ./obj_bonus/
SRC_DIR			= ./src/
INC_DIR			= ./include/
LIBFT			= ./libft/
MLX				= ./minilibx-linux/

SRCS 			= dda.c ft_checker.c ft_free.c ft_init.c ft_init_1.c keys.c mlx_utils.c raycaster.c texture.c \
     			  ft_checker_1.c ft_checkerdata.c ft_get_rgb.c ft_utils.c ft_utils_1.c main.c mlx_line.c player_move.c \
     			  scenes.c vector_utils.c ft_parse_utils.c fps.c minimap_bonus.c

SRC_FILES 		= $(addprefix $(SRC_DIR), $(SRCS))

OBJ 			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_BONUS 		= $(addprefix $(OBJ_DIR_BONUS), $(SRCS:.c=.o))

IFLAGS 			= -I$(INC_DIR) -I$(LIBFT) -I$(MLX)
LFLAGS 			= -L$(LIBFT) -lft -L$(MLX) -lmlx -lXext -lX11 -lm

all: $(NAME)
bonus : $(BONUS)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(MAKE) bonus -C $(LIBFT) --no-print-directory
	@if [ ! -f $(MLX)/libmlx.a ]; then $(MAKE) -C $(MLX) --no-print-directory; fi
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(CFLAGS)

$(BONUS): $(OBJ_DIR_BONUS) $(OBJ_BONUS)
	$(MAKE) bonus -C $(LIBFT) --no-print-directory
	@if [ ! -f $(MLX)/libmlx.a ]; then $(MAKE) -C $(MLX) --no-print-directory; fi
	$(CC) -o $@ $(OBJ_BONUS) $(LFLAGS) $(CFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR)%.c
	$(CC) -DBONUS $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT) --no-print-directory
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(OBJ_DIR_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT) --no-print-directory
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

