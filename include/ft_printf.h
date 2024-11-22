/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:08:17 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/22 12:29:33 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "./../lib/libft/include/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_printf
{
	va_list	arg;
	int		percent;
	int		len;
	int		sign;
	char	*converted;
}	t_printf;

int		printer(const char *format, t_printf *config, size_t fullsize);
size_t	percentchecker(const char *format);
size_t	multiplechar(t_printf *config);
size_t	singlechar(t_printf *config);
size_t	hexadress(t_printf *config);
size_t	inttochar(t_printf *config);
size_t	unsignedinttochar(t_printf *config);
char	*ft_itoa_unsigned(unsigned int n);
size_t	hexa(t_printf *config, size_t bol);
size_t	percent(t_printf *config);
int		writeall(const char *toprint);

#endif