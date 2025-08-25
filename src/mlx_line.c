/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:53:12 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/25 09:53:17 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static void	calculate_line_params(t_2d_vector *start, t_2d_vector *end,
		float *x_increment, float *y_increment)
{
	t_2d_vector	delta;
	int			step_count;

	delta.x = (int)(end->x - start->x);
	delta.y = (int)(end->y - start->y);
	if (abs((int)delta.x) > abs((int)delta.y))
		step_count = abs((int)delta.x);
	else
		step_count = abs((int)delta.y);
	*x_increment = delta.x / (float)step_count;
	*y_increment = delta.y / (float)step_count;
}

void	draw_line(t_mlx_image *buffer, t_2d_vector *from, t_2d_vector *to,
		uint color)
{
	t_2d_vector	current_pos;
	t_2d_vector	step;
	int			step_count;
	int			i;

	calculate_line_params(from, to, &step.x, &step.y);
	current_pos = *from;
	if (abs((int)(to->x - from->x)) > abs((int)(to->y - from->y)))
		step_count = abs((int)(to->x - from->x));
	else
		step_count = abs((int)(to->y - from->y));
	i = 0;
	while (i++ <= step_count)
	{
		put_pixel_img(buffer, current_pos.x, current_pos.y, color);
		current_pos.x += step.x;
		current_pos.y += step.y;
	}
}

int	on_exit_game(int code, void *ptr)
{
	t_cub	*cub;
	int		i;

	(void)(code);
	(void)(ptr);
	cub = static_cub(NULL);
	destroy_image(cub->mlx, cub->buffer);
	i = -1;
	while (++i < 4)
	{
		free(cub->textures[i]);
		destroy_image(cub->mlx, cub->texture[i]);
	}
	i = 0;
	while (i < (int)cub->map_height)
	{
		free(cub->maps[i]);
		i++;
	}
	free(cub->maps);
	free(cub->player);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(0);
}
