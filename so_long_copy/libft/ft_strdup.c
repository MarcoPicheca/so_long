/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:16:30 by mpicheca          #+#    #+#             */
/*   Updated: 2024/05/24 12:16:35 by mapichec         ###   ########.fr       */
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
		newstr = (char *)ft_calloc2(ft_strlen(s) + 1, sizeof(char));
		ft_strlcpy(newstr, s, ft_strlen(s) + 1);
	}
	else
		return (NULL);
	return (newstr);
}
