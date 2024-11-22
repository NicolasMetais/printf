/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:16:48 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/22 12:59:39 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft_printf.h"

size_t	conditionner(const char *format, t_printf *config, size_t i)
{
	size_t	bol;

	bol = 0;
	if (format[i] == '%' && format[i + 1] == 'c')
		bol = singlechar(config);
	if (format[i] == '%' && format[i + 1] == 's')
		bol = multiplechar(config);
	if (format[i] == '%' && format[i + 1] == 'p')
		bol = hexadress(config);
	if (format[i] == '%' && format[i + 1] == 'd')
		bol = inttochar(config);
	if (format[i] == '%' && format[i + 1] == 'i')
		bol = inttochar(config);
	if (format[i] == '%' && format[i + 1] == 'u')
		bol = unsignedinttochar(config);
	if (format[i] == '%' && format[i + 1] == 'x')
		bol = hexa(config, 0);
	if (format[i] == '%' && format[i + 1] == 'X')
		bol = hexa(config, 1);
	if (format[i] == '%' && format[i + 1] == '%')
		bol = percent(config);
	return (bol);
}

char	*buildstr(const char *format, t_printf *config, char *toprint
	, size_t fullsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	l = 0;
	while (l <= fullsize)
	{
		if (conditionner(format, config, i) == 1)
		{
			k = 0;
			while (config->converted[k])
			{
				toprint[j++] = config->converted[k];
				k++;
			}
			i = i + 2;
		}
		else
			toprint[j++] = format[i++];
		l++;
	}
	return (toprint);
}

int	printer(const char *format, t_printf *config, size_t fullsize)
{
	char	*ret;
	char	*toprint;

	toprint = ft_calloc(fullsize + 1, sizeof(char));
	ret = buildstr(format, config, toprint, fullsize);
	fullsize = (write(1, ret, ft_strlen(ret)));
	free(ret);
	free(config->converted);
	return (fullsize);
}

char	*miniconcat(char check1)
{
	char	*concat;

	concat = ft_calloc(3, sizeof(char));
	concat[0] = '%';
	concat[1] = check1;
	concat[2] = '\0';
	return (concat);

}

size_t	percentchecker(const char *format)
{
	char	*check1;
	char	*concat;
	size_t	i;

	check1 = "cspdiuxX%";
	i = 0;
	while (check1[i])
	{
		concat = miniconcat(check1[i]);
		if (ft_strnstr(format, concat, 2) != NULL )
		{
			free(concat);
			return (1);
		}
		free(concat);
		i++;
	}
	return (0);
}
