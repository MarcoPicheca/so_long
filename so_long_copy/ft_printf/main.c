/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:59:32 by mapichec          #+#    #+#             */
/*   Updated: 2024/05/06 18:19:02 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	indicatore(char form, va_list arg)
{
	int	len;

	len = 0;
	if (form == 'c')
		len += ft_putchar_len(va_arg(arg, int));
	else if (form == 's')
		len += ft_putstr_len(va_arg(arg, char *));
	else if (form == 'd' || form == 'i')
		len += ft_putnbr_len(va_arg(arg, int));
	else if (form == 'u')
		len += ft_putuns(va_arg(arg, unsigned int));
	else if (form == 'p')
		len += ft_putptr(va_arg(arg, unsigned long long));
	else if (form == 'x')
		len += ft_puthexa(va_arg(arg, unsigned int));
	else if (form == 'X')
		len += ft_puthexa_m(va_arg(arg, unsigned int));
	else if (form == '%')
		len += ft_putchar_len('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	len = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += indicatore(format[i], arg);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
