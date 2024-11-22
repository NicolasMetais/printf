/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:18:04 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/22 12:59:48 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

t_printf	*init(t_printf *config)
{
	config->percent = 0;
	config->len = 0;
	config->sign = 0;
	return (config);
}

t_printf	*countformatspecifiers(const char *format, t_printf *config)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && percentchecker(format + i) == 1)
			config->percent += 1;
		i++;
	}
	i = 0;
	if (config->len != config->percent) // ------------------------------------------------------------------------
		return (NULL);
	if (config->len == 0 && config->percent == 0)// A DEPLACER A CHECKER + TARD
		return (NULL);
	if (config->percent == 0)
		return (NULL); // ----------------------------------------------------------------------------------------
	return (config);
}

size_t	getfullsize(const char *format, t_printf *config)
{
	size_t	i;
	size_t	printsize;

	i = 0;
	printsize = ft_strlen(format);
	while (format[i])
	{
		if (format[i] == '%' && percentchecker(format + i) == 1)
		{
			printsize += ft_strlen((char *)config->arg);
			printsize -= 2;
			va_arg(config->arg, int);
			config->len += 1;
		}
		i++;
	}
	return (printsize);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*config;
	size_t		fullsize;
	size_t		retsize;

	config = ft_calloc(1, sizeof(*config));
	if (!config)
	{
		free(config);
		return (-42);
	}
	init(config);
	countformatspecifiers(format, config);
	va_start(config->arg, format);
	fullsize = getfullsize(format, config);
	va_end(config->arg);
	va_start(config->arg, format);
	retsize = printer(format, config, fullsize);
	va_end(config->arg);
	free(config);
	return (retsize);
}
/*
int main(void)
{ 
	//int test;
	//int u = 787987;

	ft_printf("%% test");
	printf("\n%% test");
	//printf("%s%s%s", "t", "t", "t");
}*/