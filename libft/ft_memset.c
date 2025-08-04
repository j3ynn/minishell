/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:46:26 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/23 17:34:40 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*buffer;
	size_t				p;

	buffer = (unsigned char *)s;
	p = 0;
	while (p < n)
	{
		buffer[p] = c;
		p ++;
	}
	return (s);
}
/*int main ()
{
	char str[] = "porcaccialamiseria";
	ft_memset(str, '7', 11);
	printf("%s\n",str);
	return (0);
}*/
