/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:23:47 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/26 17:39:12 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int j, size_t n)
{
	const unsigned char	*str;

	str = (const unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)j)
		{
			return ((void *)str);
		}
		str ++;
		n --;
	}
	return (NULL);
}
/*
int main ()
{
	printf("%s\n", (char *)ft_memchr("bonjour", 'o', 1));
}*/
