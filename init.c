/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:16:56 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 16:52:14 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_heart(t_heart *heart, char **envp)
{
	if (!heart || !envp)
	{
		write(2, "Error: Invalid parameters in init_heart\n", 40);
		exit(1);
	}
	heart->env = init_envp(envp);
	heart->input_line = NULL;
	heart->num_comds = 0;
	heart->pipes = 0;
	heart->has_pipes = false;
	heart->stdin_backup = 0;
	heart->stdout_backup = 0;
	init_pipes(heart);
	init_heredoc(heart);
	init_stdin_stdout(heart);
}

char	**init_envp(char **envp)
{
	int		len;
	char	**new_env;
	int		i;

	i = 0;
	len = arraylen(envp);
	new_env = malloc(sizeof(char *) * (len + 1));
	if (!new_env)
	{
		perror("malloc failed in copy_environment");
		exit(1);
	}
	while (envp[i])
	{
		new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
			exit(1);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

void	init_heredoc(t_heart *heart)
{
	heart->heredoc.delimiter[0] = '\0';
}

void	init_stdin_stdout(t_heart *heart)
{
	heart->stdin_backup = dup(STDIN_FILENO);
	heart->stdout_backup = dup(STDOUT_FILENO);
	if (heart->stdin_backup == -1)
	{
		write (2, "error backup stdin", 19);
		exit(1);
	}
	if (heart->stdout_backup == -1)
	{
		write (2, "error backup stdout", 20);
		close(heart->stdin_backup);
		exit(1);
	}
}

void	init_comand(t_heart *heart, int num_commands)
{
	int	i;

	heart->num_comds = num_commands;
	heart->comds = malloc(sizeof(t_comand) * num_commands);
	if (!heart->comds)
	{
		write (2, "malloc failed", 13);
		exit(1);
	}
	i = 0;
	while (i < num_commands)
	{
		heart->comds[i].heart = heart;
		heart->comds[i].comd = NULL;
		heart->comds[i].args = NULL;
		heart->comds[i].input_file = NULL;
		heart->comds[i].output_file = NULL;
		heart->comds[i].redirection = false;
		heart->comds[i].num_arg = 0;
		i++;
	}
}
