/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicheca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:09:44 by mpicheca          #+#    #+#             */
/*   Updated: 2022/11/10 11:38:43 by mpicheca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conta_cifre(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		i;

	i = conta_cifre(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	if (n < 0)
	{
		newstr[0] = '-';
		n *= -1;
	}
	newstr[i] = '\0';
	i--;
	while (n > 9)
	{
		newstr[i] = (n % 10) + 48;
		i--;
		n = n / 10;
	}
	newstr[i] = n + 48;
	return (newstr);
}
