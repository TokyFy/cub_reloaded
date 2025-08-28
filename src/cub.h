/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:02:36 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/28 10:15:29 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define WIN_WIDTH 1040
# define WIN_HEIGTH 650
# define MAP_GRID_SIZE 16

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65361
# define ARROW_LEFT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_texture
{
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			floor;
	int			cieling;

}				t_texture;

typedef struct s_data
{
	t_texture	texture;
	int			heigth;
	int			width;
	t_list		*map;
	char		**maps;
}				t_data;

typedef struct s_2d_vector
{
	float		x;
	float		y;
}				t_2d_vector;

typedef struct s_mlx_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			heigth;
	int			width;
}				t_mlx_image;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		direction;
}				t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_mlx_image	*buffer;
	char		**maps;
	uint		map_height;
	uint		map_width;
	uint		floor_color;
	uint		ceil_color;
	t_player	*player;
	t_mlx_image	*texture[4];
	char		*textures[4];
}				t_cub;

float			vect_dist(t_2d_vector *from, t_2d_vector *to);
float			normalize_angle(float angle);
void			translate_2d_vector(t_2d_vector *from, t_2d_vector *to);
void			copy_2d_vector(t_2d_vector *from, t_2d_vector *to);

void			put_pixel_img(t_mlx_image *img, unsigned int x, unsigned int y,
					int color);
void			fill_pixel_img(t_mlx_image *img, int color);
unsigned int	get_pixel_img(t_mlx_image *img, int x, int y);
void			draw_square_to_img(uint side, uint x, uint y, uint color);
t_cub			*mlx_windows(int width, int height, char *title);

void			draw_line(t_mlx_image *buffer, t_2d_vector *from,
					t_2d_vector *to, uint color);

void			find_ray_vert_intersec(t_2d_vector *from, t_2d_vector *to,
					double angle, t_cub *cub);
void			find_ray_horz_intersec(t_2d_vector *from, t_2d_vector *to,
					double angle, t_cub *cub);

void			minimaps_direction(const t_cub *cub, t_2d_vector zero);
void			minimaps_player(t_cub *cub, t_2d_vector zero);
void			minimaps(t_cub *cub, t_2d_vector zero);

void			*static_cub(void *ptr);

float			fract_part(float n);

void			set_player_position(float dx, float dy);
void			parallel_move(int code, t_cub *cub);
void			perpedicular_move(int code, t_cub *cub);
void			move_player(int code, void *ptr);
void			rotate_player(int code, t_cub *cub);

void			threed_schene(t_cub *cub);
void			render_floor_ceil(t_cub *cub, uint color_ceil,
					uint color_floor);
int				render_next_frame(void *ptr);
t_mlx_image		*load_texture(t_cub *cub, char *path);
int				on_key_press(int code, void *ptr);
int				on_exit_game(int code, void *ptr);
void			ray_vert_draw(t_cub *cub, int nth, t_2d_vector *from,
					t_2d_vector *to);
void			destroy_image(void *mlx, t_mlx_image *img);
void			normalize_maps(t_cub *cub);
void			free_cub(t_cub *cub);
void			init_player(t_cub *cub);
uint64_t		timestamp_in_ms(void);

int				ft_isspace(char c);
void			ft_error(const char *error);
int				check_map_suround(t_cub *cub);
char			gme(t_cub *cub, uint x, uint y);
int				ft_compare(char *str, char *string);
char			*b_space(int n);
char			**new_maps(t_data *data);
void			add_the_line(t_list *head, char *line);
char			*remove_jumpline(char *str);
int				rgb_to_color(int r, int g, int b);
int				get_rgb(char *str, int j, int count, int val);
int				check_struct_map(int i, int curser, char **maps);
int				check_zero_position(char **new_maps);
int				check_right_left_wall(char **array);
int				check_first_last_line(t_data *data);
int				check_element(t_data *data);
int				check_player(char **maps);
int				check_map_or_elt(char *str);
int				map_name(char *av);
char			**lst_to_str(t_list *map);
void			parse_info(t_data *data, char *tmp);
int				parse_map_data(t_data *data);
int				get_elements(t_data *data, int fd);
void			init_elmt(t_data *data, char **str);
void			init_map(t_list **map, char *line);
void			init_texture(t_texture *texture);
void			init_data(t_data *data);
void			free_map(t_list *map);
void			free_maps(char **maps);
void			destroy_data(t_data *data);
char			**lst_to_str(t_list *map);
void			free_strs(char **strs);
void			bridge(t_data *data, t_cub *cub);
int				chartodeg(char dir);
int				parse_map(t_cub *cub, char *path);
int				init_cub(t_cub *cub);
int				load(t_cub *cub);
void			reset_cub(t_cub *cub);

#endif
