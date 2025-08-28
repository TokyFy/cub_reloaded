/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:39:14 by franaivo          #+#    #+#             */
/*   Updated: 2025/08/28 10:06:21 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	on_key_press(int code, void *ptr)
{
	t_cub	*cub;

	cub = ptr;
	if (code == 65307)
		on_exit_game(code, ptr);
	if (code <= KEY_W || code == ARROW_UP || code == ARROW_DOWN)
	{
		move_player(code, ptr);
		return (1);
	}
	if (code == ARROW_RIGHT || code == ARROW_LEFT)
	{
		rotate_player(code, cub);
		return (1);
	}
	return (1);
}
