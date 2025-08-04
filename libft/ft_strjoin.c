/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:46:22 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 15:21:13 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s1 || !s2 || !s3)
		return (NULL);
	while (*s1)
		*s3 ++ = *s1 ++;
	while (*s2)
		*s3 ++ = *s2 ++;
	*s3 = '\0';
	return (s3 - (s1len + s2len));
}
/*int main (int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argv[1], argv[2]));
}*/
