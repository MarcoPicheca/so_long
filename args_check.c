/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:04:05 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/12 18:04:38 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_is_ber(char *str, int len, char *ext)
{
	int	i;

	i = 4;
	while (i > 0)
	{
		if (str[len] != ext[i])
			return (0);
		i--;
		len--;
	}
	return (1);
}

int args_check(char *str)
{
	int	i;
	int	fd;

	i = ft_strlen(str);
	fd = open(str, O_RDONLY | __O_DIRECTORY);
	if (!ft_is_ber(str, i, ".ber") || fd != -1)
	{
		ft_printf("Invalid file!\n");
		exit(1);
		return (1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Invalid open!\n");
		exit(2);
		return (1);
	}
	close(fd);
	return (0);
}