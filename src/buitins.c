/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:28:24 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 17:42:37 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_parent_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

static void	run_builtin_parent2(t_comand *cmd, t_heart *heart, int is_export)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (is_export)
			heart->env = export_env_var(heart->env, cmd->args[i], heart);
		else
			heart->env = unset_env_var(heart->env, cmd->args[i], heart);
		i++;
	}
}

void	run_builtin_parent(t_comand *cmd, t_heart *heart)
{
	if (!cmd || !cmd->comd)
		return ;
	if (!ft_strcmp(cmd->comd, "cd"))
	{
		if (!cmd->args[1])
			ft_putendl_fd("minishell: cd: missing argument", 2);
		else if (chdir(cmd->args[1]) == -1)
			perror("minishell: cd");
	}
	else if (!ft_strcmp(cmd->comd, "unset"))
		run_builtin_parent2(cmd, heart, 0);
	else if (!ft_strcmp(cmd->comd, "export"))
		run_builtin_parent2(cmd, heart, 1);
	else if (!ft_strcmp(cmd->comd, "exit"))
	{
		free_all(heart);
		exit(heart->last_status);
	}
}

int	is_child_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	return (0);
}
