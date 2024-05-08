/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:16:30 by mpicheca          #+#    #+#             */
/*   Updated: 2022/11/08 14:42:00 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*newstr;

	if (!s)
		return (NULL);
	if (s)
	{
		newstr = (char *)malloc(ft_strlen(s) + 1);
		ft_strlcpy(newstr, s, ft_strlen(s) + 1);
	}
	else
		return (NULL);
	return (newstr);
}
