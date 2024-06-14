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

char	*ft_strjoina(char const *s1, char const *s2)
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
		while (s1 && s1[i])
			newstr[j++] = s1[i++];
		while (s2 && s2[k])
			newstr[j++] = s2[k++];
		newstr[j] = '\0';
		return (newstr);
	}
	return (NULL);
}

char	*ft_strjoin2(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*newstr;

	newstr = ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	i = -1;
	while (str1[++i])
		newstr[i] = str1[i];
	j = 0;
	while (str2[j])
		newstr[i++] = str2[j++];
	newstr[ft_strlen(str1) + ft_strlen(str2)] = '\0';
	free(str1);
	return (newstr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	if (!str1)
	{
		str1 = (char *)ft_calloc(1, sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2 || (str1[0] == '\0' && str2[0] == '\0'))
	{
		free(str1);
		free(str2);
		return (NULL);
	}
	return (ft_strjoin2(str1, str2));
}
