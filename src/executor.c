/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:47:22 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 17:47:23 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	setup_redirections(t_comand *cmd, t_heart *heart, int i)
{
	int	fd;

	if (i > 0)
		dup2(heart->pipes[i - 1][0], STDIN_FILENO);
	if (i < heart->num_comds - 1)
		dup2(heart->pipes[i][1], STDOUT_FILENO);
	if (cmd->input_file)
	{
		fd = open_input_file(cmd, heart);
		if (fd != -1)
		{
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
	}
	if (cmd->output_file)
	{
		fd = open_output_file(cmd);
		if (fd != -1)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
	}
	close_all_pipes_child(heart);
}

static void	child_process(t_comand *cmd, t_heart *heart, int i)
{
	char	*path;

	setup_redirections(cmd, heart, i);
	if (is_child_builtin(cmd->comd))
		run_builtin_child(cmd, heart);
	path = get_path(cmd->comd, heart->env);
	if (path)
	{
		execve(path, cmd->args, heart->env);
		ft_putstr_fd("minishell: ", 2);
		perror(cmd->comd);
		free(path);
		exit(127);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->comd, 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
}

int	execute_commands(t_heart *heart)
{
	int		i;
	pid_t	*pids;

	if (heart->num_comds == 1 && is_parent_builtin(heart->comds[0].comd))
	{
		run_builtin_parent(&heart->comds[0], heart);
		return (0);
	}
	init_pipes(heart);
	pids = malloc(sizeof(pid_t) * heart->num_comds);
	i = 0;
	while (i < heart->num_comds)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			child_process(&heart->comds[i], heart, i);
		i++;
	}
	free_pipes(heart);
	heart->last_status = wait_all(pids, heart->num_comds);
	free(pids);
	return (heart->last_status);
}
