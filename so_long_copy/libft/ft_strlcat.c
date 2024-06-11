/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:00:18 by mpicheca          #+#    #+#             */
/*   Updated: 2022/10/20 17:05:22 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			d;
	size_t			s;
	size_t			result;
	size_t			i;
	char			*cast_s;

	if (!dst || !src)
		return (0);
	cast_s = (char *)src;
	i = 0;
	s = ft_strlen(cast_s);
	d = ft_strlen(dst);
	result = s + d;
	if (size <= d)
		result = size + s;
	if (size > d)
		result = s + d;
	while (cast_s[i] && size > (d + 1))
		dst[d++] = src[i++];
	if (size > d)
		dst[d] = '\0';
	return (result);
}
