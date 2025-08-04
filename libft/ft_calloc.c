/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:19:28 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 12:29:13 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	p = malloc(nmemb * size);
	if ((!p) || (p != 0 && size > SIZE_MAX / nmemb))
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*int main ()
{
	char	*arr = ft_calloc(5, sizeof(char));
	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	return (0);
}*/
