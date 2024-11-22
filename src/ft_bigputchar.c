/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigputchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:04:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/22 12:59:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

int	getsize(const char *format, t_printf *config)
{
	size_t	size;

	size = 0;
	size = ft_strlen(format) - (2 * config->percent)
		+ ft_strlen((char *)config->arg);
	return (size + 1);
}