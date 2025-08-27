/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <llalatia@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:16:36 by llalatia          #+#    #+#             */
/*   Updated: 2024/05/27 16:02:12 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*atlast;

	atlast = *lst;
	if (!atlast)
		*lst = new;
	else
	{
		while (atlast->next)
			atlast = atlast->next;
		atlast->next = new;
	}
}
