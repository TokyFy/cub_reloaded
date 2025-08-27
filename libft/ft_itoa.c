/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:16:07 by llalatia          #+#    #+#             */
/*   Updated: 2024/03/15 09:45:15 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n < 0 || n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

static char	*alloue(int n)
{
	char	*nb;

	nb = (char *)malloc(sizeof(char) * (count_digit(n) + 1));
	if (!nb)
		return (0);
	return (nb);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	j = count_digit(n);
	nb = alloue(n);
	if (!nb)
		return (0);
	if (n < 0)
	{
		nb[0] = '-';
		n *= -1 + (i++*0);
	}
	nb[j] = '\0';
	while (n > 0)
	{
		nb[j - 1] = (n % 10) + '0';
		n /= 10 + (j--*0);
	}
	return (nb);
}
