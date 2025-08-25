/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:32:56 by llalatia          #+#    #+#             */
/*   Updated: 2024/03/01 12:01:11 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char			*s;
// 	unsigned int	i;
// 	unsigned int	j;

// 	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	i = 0;
// 	j = 0;
// 	if (s == 0)
// 		return (0);
// 	while (s1[j] != '\0')
// 	{
// 		s[i] = s1[j];
// 		i++;
// 		j++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		s[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	s[i] = '\0';
// 	return (s);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (s == 0)
		return (free(s), NULL);
	while (s1[j] != '\0')
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	s[i] = '\0';
	return (s);
}
