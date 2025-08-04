/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:59:49 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 15:22:42 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*j;
	int		i;
	int		fs1;
	int		h;

	i = 0;
	h = 0;
	if (!s1 || !set)
		return (NULL);
	fs1 = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i ++;
	while (fs1 >= i && ft_strchr(set, s1[fs1]))
		fs1 --;
	j = (char *)malloc((fs1 - i + 2) * sizeof(char));
	if (!j)
		return (NULL);
	while (i <= fs1)
		j[h++] = s1[i++];
	j[h] = '\0';
	return (j);
}
/*int main ()
{
	printf ("%s\n", ft_strtrim("parinasola", "pari"));
}*/
