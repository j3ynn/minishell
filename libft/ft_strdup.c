/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:31:40 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/15 15:50:15 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_dup;
	char	*s2;

	len = ft_strlen(s);
	s_dup = malloc(sizeof(char) * (len + 1));
	s2 = s_dup;
	while (*s)
	{
		*s_dup = *s;
		s_dup ++;
		s ++;
	}
	*s_dup = '\0';
	return (s2);
}
/*int main (int ac, char **av)
{
	printf("%s\n", ft_strdup((const char *)av[1]));
}*/
