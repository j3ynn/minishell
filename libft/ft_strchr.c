/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:30:04 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 10:34:23 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	while (*str)
	{
		if (*str == (char)s)
			return ((char *)str);
		str ++;
	}
	if (s == '\0' && (char)s == '\0')
		return ((char *)str);
	return (0);
}
/*int main(int argc, char **argv)
{
	int s = '\0';
	printf("%s\n", ft_strchr(argv[1], s));
}*/
