/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:36:40 by mpicheca          #+#    #+#             */
/*   Updated: 2024/04/04 14:26:15 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	*newstr;

	if (!s1 && !s2)
		return (NULL);
	else
	{
		i = 0;
		k = 0;
		j = 0;
		newstr = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1));
		while (s1[i])
			newstr[j++] = s1[i++];
		while (s2[k])
			newstr[j++] = s2[k++];
		newstr[j] = '\0';
		return (newstr);
	}
	return (NULL);
}
