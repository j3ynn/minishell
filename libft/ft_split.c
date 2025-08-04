/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:00 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/19 15:26:42 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str, char d)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != d)
		{
			count ++;
			while (*str != d && *str != '\0')
				str ++;
		}
		else
			str ++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**phrase;
	size_t	p;
	size_t	len;

	phrase = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	p = 0;
	if (!phrase)
		return (0);
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = 0;
			while (*s != c && *s != '\0')
			{
				len ++;
				s ++;
			}
			phrase[p++] = ft_substr(s - len, 0, len);
		}
		else
			s ++;
	}
	phrase[p] = 0;
	return (phrase);
}
/*int main(int argc, char **argv)
{
	int	p;
	char	**strr;
	strr = ft_split(argv[1] , ' ');
	p = 0;
	while (strr[p])
	{
		printf("%s\n", strr[p]);
		p++;
	}
	return (0);
}*/
