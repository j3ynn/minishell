/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:26:04 by jbellucc          #+#    #+#             */
/*   Updated: 2024/11/18 18:40:40 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int p)
{
	if (p >= 65 && p <= 90)
	{
		return (p + 32);
	}
	else
	{
		return (p);
	}
}
/*int main(int argc, char **argv)
{
	printf("%d\n", ft_tolower(argv[0][1]));
}*/
