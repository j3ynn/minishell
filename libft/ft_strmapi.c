/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:28:24 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/27 15:23:38 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		count;
	int		p;

	if (!s || !f)
		return (NULL);
	p = 0;
	count = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str < s)
		return (NULL);
	while (s[p])
	{
		str[p] = f(p, s[p]);
		p ++;
	}
	str[p] = '\0';
	return (str);
}
