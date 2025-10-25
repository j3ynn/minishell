/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitins2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:33:22 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 17:42:44 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	run_builtin_child2(t_comand *cmd)
{
	int	i;
	int	j;
	int	newline;

	newline = 1;
	i = 1;
	while (cmd->args[i] && cmd->args[i][0] == '-' && cmd->args[i][1] == 'n')
	{
		j = 1;
		while (cmd->args[i][j] == 'n')
			j++;
		if (cmd->args[i][j] != '\0')
			break ;
		newline = 0;
		i++;
	}
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
}

void	run_builtin_child(t_comand *cmd, t_heart *heart)
{
	char	cwd[1024];
	int		i;

	if (!ft_strcmp(cmd->comd, "echo"))
	{
		run_builtin_child2(cmd);
		exit(0);
	}
	else if (!ft_strcmp(cmd->comd, "pwd"))
	{
		if (getcwd(cwd, sizeof(cwd)))
			printf("%s\n", cwd);
		exit(0);
	}
	else if (!ft_strcmp(cmd->comd, "env"))
	{
		i = 0;
		while (heart->env[i])
			printf("%s\n", heart->env[i++]);
		exit(0);
	}
}
