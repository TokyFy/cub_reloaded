/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:49:58 by llalatia          #+#    #+#             */
/*   Updated: 2024/02/23 15:05:10 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	len_s;
	unsigned int	len_d;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (!(size > len_d))
		return (size + len_s);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - len_d - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_s + len_d);
}
