/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:33:59 by mpicheca          #+#    #+#             */
/*   Updated: 2022/10/17 16:04:01 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strchr2(char *buff, int n)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	if (n == '\0')
		return ((char *)&buff[ft_strlen(buff)]);
	while (buff[i])
	{
		if (buff[i] == (char) n)
			return ((char *)&buff[i]);
		i++;
	}
	return (0);
}
