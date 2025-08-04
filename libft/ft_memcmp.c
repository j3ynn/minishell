/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:45:31 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 14:56:08 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	p;
	char	*str1;
	char	*str2;	

	p = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (p < n)
	{
		if (str1[p] != str2[p])
		{
			return ((unsigned char)str1[p] - (unsigned char)str2[p]);
		}
		p ++;
	}
	return (0);
}
/*int main()
{
	printf("%d\n", ft_memcmp("ciao","ciao",6));
}*/
