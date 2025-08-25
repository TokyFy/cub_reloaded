/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalatia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:37:46 by llalatia          #+#    #+#             */
/*   Updated: 2024/05/27 16:13:19 by llalatia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todel;
	t_list	*temp;

	todel = *lst;
	while (todel)
	{
		temp = todel;
		todel = todel->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
