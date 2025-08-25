#include "cub.h"
#include <fcntl.h>
#include <stdlib.h>

char	**lst_to_str(t_list *map)
{
	int		i;
	int		j;
	t_list	*head_map;
	char	**mymap;

	i = 0;
	j = ft_lstsize(map);
	head_map = map;
	mymap = malloc(sizeof(char *) * (j + 1));
	if (!mymap)
		return (NULL);
	while (i < j)
	{
		mymap[i] = ft_strdup(head_map->content);
		head_map = head_map->next;
		i++;
	}
	mymap[i] = NULL;
	return (mymap);
}

void	parse_info(t_data *data, char *tmp)
{
	int		i;
	char	**split;

	if (check_map_or_elt(tmp) || data->map != NULL)
	{
		init_map(&data->map, tmp);
		if (data->width < (int)ft_strlen(tmp))
			data->width = ft_strlen(tmp);
	}
	else
	{
		i = 0;
		split = ft_split(tmp, ' ');
		if (split == NULL)
			return ;
		if (split[0] == NULL)
			return ((void)(free(split)));
		while (split[i] != NULL)
			i++;
		if (i > 2)
			return ((void)(free_maps(split)));
		init_elmt(data, split);
		free_maps(split);
	}
}

int	parse_map_data(t_data *data)
{
	char	**newmaps;

	newmaps = new_maps(data);
	free_maps(data->maps);
	data->maps = newmaps;
	if ((check_first_last_line(data) == 0))
	{
		return (0);
	}
	else if (check_struct_map(0, 0, newmaps) == 0 || check_player(newmaps) != 1)
	{
		printf("Map / Player error\n");
		return (0);
	}
	else if (check_zero_position(newmaps) == 0)
	{
		printf("Erreur m or p\n");
		return (0);
	}
	return (1);
}

int	get_elements(t_data *data, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line)
	{
		tmp = remove_jumpline(line);
		free(line);
		parse_info(data, tmp);
		free(tmp);
		line = get_next_line(fd);
	}
	data->heigth = ft_lstsize(data->map);
	data->maps = lst_to_str(data->map);
	free_map(data->map);
	data->map = NULL;
	if (check_element(data) == 0 || parse_map_data(data) == 0)
		return (0);
	return (1);
}

void	free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures[i])
			free(cub->textures[i]);
		i++;
	}
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->player)
		free(cub->player);
	if (cub->maps)
		free_strs(cub->maps);
	free_textures(cub);
}

void	*static_cub(void *ptr)
{
	static void	*cub;

	if (cub == NULL)
	{
		cub = ptr;
		return (NULL);
	}
	return (cub);
}

void	init_cub(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGTH, "cub3D");
	cub->buffer = ft_calloc(sizeof(t_mlx_image), 1);
	cub->buffer->img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGTH);
	cub->buffer->width = WIN_WIDTH;
	cub->buffer->heigth = WIN_HEIGTH;
	cub->buffer->addr = mlx_get_data_addr(cub->buffer->img,
			&cub->buffer->bits_per_pixel, &cub->buffer->line_length,
			&cub->buffer->endian);
}

int	load(t_cub *cub)
{
	int	i;

	cub->texture[0] = load_texture(cub, cub->textures[0]);
	cub->texture[1] = load_texture(cub, cub->textures[1]);
	cub->texture[2] = load_texture(cub, cub->textures[2]);
	cub->texture[3] = load_texture(cub, cub->textures[3]);
	i = 0;
	if (cub->texture[0] == NULL || cub->texture[1] == NULL
		|| cub->texture[2] == NULL || cub->texture[3] == NULL)
	{
		ft_putstr_fd("Error : non xpm file found \n", STDERR_FILENO);
		while (i < 4)
		{
			destroy_image(cub->mlx, cub->texture[i]);
			cub->texture[i] = NULL;
			i++;
		}
		destroy_image(cub->mlx, cub->buffer);
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
		return (0);
	}
	return (1);
}

void	destroy_image(void *mlx, t_mlx_image *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx, img->img);
	free(img);
	return ;
}

void	bridge(t_data *data, t_cub *cub)
{
	cub->ceil_color = data->texture.cieling;
	cub->floor_color = data->texture.floor;
	cub->textures[0] = ft_strdup(data->texture.path_ea);
	cub->textures[1] = ft_strdup(data->texture.path_no);
	cub->textures[2] = ft_strdup(data->texture.path_so);
	cub->textures[3] = ft_strdup(data->texture.path_we);
	cub->map_height = data->heigth;
	cub->map_width = data->width;
	cub->maps = data->maps;
	data->maps = NULL;
	cub->player = malloc(sizeof(t_player));
	cub->player->direction = 0;
	cub->player->pos_x = 1.5;
	cub->player->pos_y = 1.5;
}

int	parse_map(t_cub *cub, char *path)
{
	t_data	*data;
	int		fd;

	data = malloc(sizeof(t_data));
	fd = -1;
	init_data(data);
	if (!map_name(path))
	{
		printf("wrong argument _ cub3d map.cub\n");
		free(data);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		free(data);
		return (0);
	}
	init_data(data);
	int err = get_elements(data, fd);
	if(err)
		bridge(data, cub);
	destroy_data(data);
	free(data);
	if (!err || (cub->ceil_color <= 0 || cub->floor_color <= 0))
		return (0);
	return (err);
}

void	init_player(t_cub *cub)
{
	(void)(cub);
	return ;
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
	{
		ft_putstr_fd("usage: ./cub3D <file.cub>\n", 2);
		return (1);
	}
	cub.player = NULL;
	cub.maps = NULL;
	cub.textures[0] = NULL;
	cub.textures[1] = NULL;
	cub.textures[2] = NULL;
	cub.textures[3] = NULL;

	if (!parse_map(&cub, av[1]))
	{
		free_cub(&cub);
		return (1);
	}
	init_cub(&cub);
	init_player(&cub);
	if (!load(&cub))
		return (free_cub(&cub), 1);
	static_cub(&cub);
	mlx_hook(cub.win, 02, 1L << 0, on_key_press, &cub);
	mlx_hook(cub.win, 17, 0, on_exit_game, &cub);
	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx);
}
