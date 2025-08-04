/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:28:21 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/23 17:07:49 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	p;
	int	ris;
	int	sign;

	p = 0;
	ris = 0;
	sign = 1;
	while ((str[p] == ' ') || (str[p] >= 9 && str[p] <= 13))
		p ++;
	if (str[p] == '-' || str[p] == '+')
	{
		if (str[p] == '-')
		{
			sign = -1;
		}
		p++;
	}
	while ((str[p] >= 48) && (str[p] <= 57))
	{
		ris = ris * 10 + (str[p] - 48);
		p ++;
	}
	return (sign * ris);
}
/*int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
		printf("%d", ft_atoi(argv[1]));
}*/
