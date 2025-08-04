/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:41:25 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/11 11:43:27 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int p)
{
	if (p >= 97 && p <= 122)
	{
		return (p - 32);
	}
	else
	{
		return (p);
	}
}

/*int main(int argc, char **argv)
{
	printf("%d\n", ft_toupper(argv[1][0]));
}*/
