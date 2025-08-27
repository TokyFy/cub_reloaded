/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:14:49 by llalatia          #+#    #+#             */
/*   Updated: 2024/03/01 08:31:30 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = start;
	if (ft_strlen(s) == 0 || j > ft_strlen(s))
		j = ft_strlen(s);
	if (len > ft_strlen(s) - j)
		len = ft_strlen(s) - j;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
