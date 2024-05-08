/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:50:48 by mpicheca          #+#    #+#             */
/*   Updated: 2022/10/17 17:24:49 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	b;
	void	*p;

	b = nmemb * size;
	if (b / nmemb != size && nmemb != 0)
		return (NULL);
	p = malloc(b);
	if (!p)
		return (NULL);
	ft_bzero(p, b);
	return (p);
}
