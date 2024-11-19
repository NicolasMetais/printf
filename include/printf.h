/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:08:17 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/19 20:16:56 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "./../lib/libft/include/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_printf
{
	va_list	arg;
	int		percent;
	int		len;
	int		sign;
}	t_printf;

#endif