/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:10:09 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/24 11:49:40 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	p;

	p = 0;
	if (!n || !str1 || !str2)
		return (0);
	while (p < n && (str1[p] != '\0' || str2[p] != '\0'))
	{
		if (str1[p] != str2[p])
			return ((unsigned char)str1[p] - (unsigned char)str2[p]);
		p ++;
	}
	return (0);
}
/*int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d,\n", ft_strncmp(argv[1], argv[2], 7));
		printf("%d", strncmp(argv[1], argv[2], 7));
	}
}*/
