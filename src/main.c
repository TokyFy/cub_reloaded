/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:54:15 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/27 16:05:56 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	main(int ac, char **av)
{
	t_cub	cub;

	reset_cub(&cub);
	if (ac != 2)
	{
		ft_error("usage: ./cub3D <file.cub>");
		return (1);
	}
	if (!parse_map(&cub, av[1]) || !init_cub(&cub))
	{
		free_cub(&cub);
		return (1);
	}
	init_player(&cub);
	if (!load(&cub))
		return (free_cub(&cub), 1);
	static_cub(&cub);
	mlx_hook(cub.win, 02, 1L << 0, on_key_press, &cub);
	mlx_hook(cub.win, 17, 0, on_exit_game, &cub);
	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx);
}
