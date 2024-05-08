/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:43 by mpicheca          #+#    #+#             */
/*   Updated: 2022/11/14 16:16:40 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*c;

	if (!del || !(*lst))
		return ;
	while (*lst)
	{
		del((*lst)-> content);
		c = *lst;
		*lst = c -> next;
		free(c);
	}
	*lst = NULL;
}
