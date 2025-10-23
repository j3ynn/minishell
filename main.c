/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:59:23 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/21 15:57:30 by jbellucc         ###   ########.fr       */
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
	setup_signals();
	while (1)
	{
		line = readline("minishell$ ");	
		if (!line)
		{
			printf("exit\n");
			free_all(&heart);
			exit(heart.last_status);
		}
		if (*line)
			add_history(line);
		if (parse_input(&heart, line) == 0)
		{
			execute_commands(&heart);
			free_commands(&heart);
		}
		else
		{
			free(line);
			free_commands(&heart);
			continue;
		}
		free(line);
	}
	return (0);
}
