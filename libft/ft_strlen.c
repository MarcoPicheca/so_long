/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:00:40 by mpicheca          #+#    #+#             */
/*   Updated: 2024/05/06 18:29:46 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen_2(const char *s, int flag)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	else if (flag == 1)
	{
		while (s[i] != '\n' && s[i])
			i++;
		return (i);
	}
	return (0);
}