/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:17:41 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/22 13:53:56 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"
#include <string.h>

void	converthexa(unsigned long long c, t_printf *config)
{
	char				*base;
	int					i;
	char				*ret;
	unsigned long long 	temp;

	i = 0;
	temp = c;
	config->converted = "";
	base = "0123456789abcdef";
	while ((temp / 16) > 0)
	{
		temp /= 16;
		i++;
	}
	ret = ft_calloc(i + 1, sizeof(char));
	temp = i;
	while ((c / 16) > 0)
	{
		ret[i] = base[(c % 16)];
		c /= 16;
		i--;
	}
	ret[i] = base[(c % 16)];
	ret[temp + 1] = '\0';
	config->converted = ret;
}

size_t	hexadress(t_printf *config)
{
	unsigned long long		c;

	c = va_arg(config->arg, unsigned long long);
	converthexa(c, config);
	ft_memmove(config->converted + 2, config->converted,
		ft_strlen(config->converted) + 1);
	config->converted[0] = '0';
	config->converted[1] = 'x';
	return (1);
}

size_t	hexa(t_printf *config, size_t bol)
{
	int		c;
	size_t	i;

	c = va_arg(config->arg, int);
	converthexa(c, config);
	i = 0;
	if (bol == 1)
	{
		while (config->converted[i])
		{
			config->converted[i] = ft_toupper(config->converted[i]);
			i++;
		}
	}
	return (1);
}

size_t	inttochar(t_printf *config)
{
	int		c;

	c = va_arg(config->arg, int);
	config->converted = ft_itoa(c);
	return (1);
}

size_t	unsignedinttochar(t_printf *config)
{
	int		c;

	c = va_arg(config->arg, int);
	config->converted = ft_itoa_unsigned(c);
	return (1);
}
