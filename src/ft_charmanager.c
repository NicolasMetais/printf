/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charmanager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:44:24 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/22 15:37:17 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	multiplechar(t_printf *config)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = ft_calloc(ft_strlen((char *)config->arg) - (2 * config->percent),
			sizeof(char));
	ret = va_arg(config->arg, char *);
	config->converted = ret;
	return (1);
}

size_t	singlechar(t_printf *config)
{
	char	c;
	char	*ret;

	ret = ft_calloc(2, sizeof(char));
	c = va_arg(config->arg, int);
	ret[0] = c;
	ret[1] = '\0';
	config->converted = ret;
	return (2);
}

size_t	percent(t_printf *config)
{
	char	*ret;

	ret = ft_calloc(2, sizeof(char));
	va_arg(config->arg, int);
	ret[0] = '%';
	ret[1] = '\0';
	config->converted = ret;
	return (1);
}
