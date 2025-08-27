/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:22:08 by llalatia          #+#    #+#             */
/*   Updated: 2024/02/27 14:39:45 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	char			*str;
	char			to_find;

	i = 0;
	str = (char *)s;
	to_find = (char)c;
	while (i < n)
	{
		if (str[i] == to_find)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
