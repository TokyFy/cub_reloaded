/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:07:28 by llalatia          #+#    #+#             */
/*   Updated: 2024/03/01 14:14:02 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (trim(set, s1[i]) == 1)
	{
		i++;
	}
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (trim(set, s1[j]) == 1)
	{
		j--;
	}
	return (ft_substr(s1, i, (j - i + 1)));
}
