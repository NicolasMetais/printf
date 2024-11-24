/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:17:41 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/24 23:13:44 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"
#include <string.h>

size_t	gethexsize(unsigned long long c)
{
	size_t	i;

	i = 0;
	while ((c / 16) > 0)
	{
		c /= 16;
		i++;
	}
	return (i);
}

size_t	converthexadress(unsigned long long c)
{
	char	*base;
	char	*toprint;
	size_t	i;
	size_t	size;

	i = 0;
	base = "0123456789abcdef";
	size = gethexsize(c);
	toprint = ft_calloc(sizeof(char), size + 2);
	if (!toprint)
		return (0);
	while ((c / 16) > 0)
	{
		toprint[i] = base[(c % 16)];
		c /= 16;
		i++;
	}
	toprint[i] = base[(c % 16)];
	toprint[i + 1] = '\0';
	while (i > 0)
	{
		write(1, &toprint[i], 1);
		i--;
	}
	write(1, &toprint[i], 1);
	free(toprint);
	return (size + 1);
}

size_t	converthexa(unsigned long long c, size_t bol, size_t sign)
{
	char	*base;
	char	*toprint;
	size_t	i;
	size_t	size;

	i = 0;
	base = "0123456789abcdef";
	if (bol == 1)
		base = "0123456789ABCDEF";
	size = gethexsize(c);
	toprint = ft_calloc(sizeof(char), size + 2);
	if (!toprint)
		return (0);
	while ((c / 16) > 0 && i < 7)
	{
		toprint[i] = base[(c % 16)];
		c /= 16;
		i++;
	}
	toprint[i] = base[(c % 16)];
	toprint[i + 1] = '\0';
	while (i > 0)
	{
		write(1, &toprint[i], 1);
		i--;
	}
	write(1, &toprint[i], 1);
	free(toprint);
	if (sign == 1)
		return (8);
	return (size + 1);
}

size_t	hexadress(va_list arg)
{
	unsigned long long		c;
	int						len;

	c = va_arg(arg, unsigned long long);
	if (c == 0)
		return (write (1, "(nil)", 5));
	write (1, "0x", 2);
	len = converthexadress(c) + 2;
	return (len);
}

size_t	hexa(va_list arg, size_t bol)
{
	int		c;
	size_t	sign;

	sign = 0;
	c = va_arg(arg, int);
	if (c < 0)
		sign++;
	return (converthexa((int)c, bol, sign));
}
