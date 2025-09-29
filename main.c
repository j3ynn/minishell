/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: je <je@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:59:23 by jbellucc          #+#    #+#             */
/*   Updated: 2025/08/12 16:28:10 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_heart	heart;
	char	*line;

	(void)argc;
	(void)argv;
	init_heart(&heart, envp);
	while (1)
	{
		line = readline("minishell$ ");	
		if (!line)
			break ;
		if (parse_input(&heart, line) == 0)
			execute_commands(&heart);
		free_commands(&heart);
		free(line);
	}
	return (0);
}
