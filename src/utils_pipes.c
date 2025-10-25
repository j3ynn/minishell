/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:27:06 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 18:27:39 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_pipes(t_heart *heart)
{
	int	i;

	if (!heart || heart->num_comds <= 1)
	{
		heart->pipes = NULL;
		return ;
	}
	heart->pipes = malloc(sizeof(int *) * (heart->num_comds - 1));
	if (!heart->pipes)
	{
		perror("malloc");
		exit(1);
	}
	i = 0;
	while (i < heart->num_comds - 1)
	{
		heart->pipes[i] = malloc(sizeof(int) * 2);
		if (!heart->pipes[i] || pipe(heart->pipes[i]) == -1)
		{
			perror("pipe");
			exit(1);
		}
		i++;
	}
}

void	free_pipes(t_heart *heart)
{
	int	i;

	if (!heart || !heart->pipes)
		return ;
	i = 0;
	while (i < heart->num_comds - 1)
	{
		if (heart->pipes[i])
		{
			close(heart->pipes[i][0]);
			close(heart->pipes[i][1]);
			free(heart->pipes[i]);
		}
		i++;
	}
	free(heart->pipes);
	heart->pipes = NULL;
}

void	close_all_pipes_child(t_heart *heart)
{
	int	i;

	if (!heart || !heart->pipes)
		return ;
	i = 0;
	while (i < heart->num_comds - 1)
	{
		close(heart->pipes[i][0]);
		close(heart->pipes[i][1]);
		i++;
	}
}
