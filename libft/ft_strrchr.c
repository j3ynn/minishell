/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:19:52 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 10:39:25 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int	p;

	p = 0;
	while (str[p] != '\0')
		p ++;
	while (p >= 0)
	{
		if (str[p] == (char)s)
			return ((char *)(str + p));
		p --;
	}
	if (s == '\0')
		return ((char *)(str + p));
	return (NULL);
}
/*int main(int argc, char **argv)
{
	int s = 's';
	printf("%s,\n", ft_strrchr(argv[1], s));
}*/
