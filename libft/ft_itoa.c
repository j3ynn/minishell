/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:57:06 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/26 15:08:50 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count ++;
	}
	while (n > 0)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nbr;
	int		count;

	nbr = n;
	count = count_digits(n);
	if (nbr == 0)
		return (ft_strdup("0"));
	c = (char *)malloc(sizeof(char) * (count + 1));
	if (!c)
		return (NULL);
	c[count] = '\0';
	count --;
	while (nbr != 0)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			c[0] = '-';
		}
		c[count--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (c);
}
/*int main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-13320));
	printf("%s\n", ft_itoa(-2147483648LL));
}*/
