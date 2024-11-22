/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:49:57 by nmetais           #+#    #+#             */
/*   Updated: 2024/11/21 21:46:52 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Copier une zone mémoire */
#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdest;

	csrc = (const char *)src;
	cdest = (char *)dest;
	if (csrc == NULL && cdest == NULL)
		return (NULL);
	if (cdest <= csrc)
		ft_memcpy(dest, src, n);
	else
	{
		csrc += n;
		cdest += n;
		while (n--)
			*--cdest = *--csrc;
	}
	return (dest);
}
/*
int main(void)
{
	char cpy[] = "consectetur";
	char dest[];
	ft_memmove(dest, cpy, 5);
	
}*/
