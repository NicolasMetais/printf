/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:16:48 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/20 01:55:45 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/printf.h"

int	printer(const char *format, t_printf *config)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (format[i])
		ret = conditionner(format, config, i);
	return (-1);
}

size_t	percentchecker(const char *format)
{
	char	*check;
	size_t	i;

	check = "cspdiuxX%";
	i = 0;
	while (check[i])
	{
		if (ft_strncmp(format, check[i], 1) == 0)
			return (1);
	}
	return (0);
}

char	*conditionner(const char *format, t_printf *config, size_t i)
{
	char	*ret;

	config->len = 0;
	if (format[i] == '%' && format[i + 1] == 'c')
		ret = (config->arg); //reprend ici et check si len de 1? josepo
	if (format[i] == '%' && format[i + 1] == 's')
		return (ret);
	if (format[i] == '%' && format[i + 1] == 'p')
		return (ret);
	if (format[i] == '%' && format[i + 1] == 'd')
		return (ret);
	if (format[i] == '%' && format[i + 1] == 'i')
		return (ret);
	if (format[i] == '%' && format[i + 1] == 'u')
		return (ret);
	if (format[i] == '%' && format[i + 1] == 'x')
		return (ret);
	if (format[i] == '%' && format[i + 1] == 'X')
		return (ret);
	if (format[i] == '%' && format[i + 1] == '%')
		return (ret);
	return (ret);
}