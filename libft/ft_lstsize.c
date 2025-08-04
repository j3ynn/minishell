/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:03:39 by jbellucc          #+#    #+#             */
/*   Updated: 2024/12/22 17:23:28 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	p;

	p = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		p ++;
		lst = lst -> next;
	}
	return (p);
}
