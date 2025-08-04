/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:50:25 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/24 10:47:41 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			p;

	p = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (!cdest || !csrc)
		return (NULL);
	if (csrc > cdest)
	{
		while (p < n)
		{
			cdest[p] = csrc[p];
			p ++;
		}
	}
	else
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	return (dest);
}
/*
int main ()
{
	char	src[] = "lorem ipsum dolor sit amet";
    // char	src[]="porcaccialamiseria";
	// char	dest[];
    char	*dest;
    dest = src + 1;
	ft_memmove(src, dest, 8);
	printf("%s\n", dest);
	return (0);
}*/
