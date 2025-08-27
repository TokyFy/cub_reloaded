/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:16:59 by llalatia          #+#    #+#             */
/*   Updated: 2024/02/21 16:19:25 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	char			*temp;
	unsigned int	i;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
