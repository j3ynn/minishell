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
	else if(!ft_strcmp(cmd->comd, "unset"))
	{
		int i = 1;
		while (cmd->args[i])
		{
			heart->env = unset_env_var(heart->env, cmd->args[i], heart);
			i++;
		}
	}
	else if(!ft_strcmp(cmd->comd, "export"))
	{
		int i = 0;
		while (cmd->args[i])
		{
			heart->env = export_env_var(heart->env, cmd->args[i], heart);
			i++;
		}
	}
	else if (!ft_strcmp(cmd->comd, "exit"))
	{
		free_all(heart);
		exit(0);
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

void	run_builtin_child(t_comand *cmd, t_heart *heart)
{
	int	i;

	if (!ft_strcmp(cmd->comd, "echo"))
	{
		i = 1;
		while (cmd->args[i])
		{
			printf("%s", cmd->args[i]);
			if (cmd->args[i + 1])
				printf(" ");
			i++;
		}
		printf("\n");
		exit(0);
	}
	else if (!ft_strcmp(cmd->comd, "pwd"))
	{
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)))
			printf("%s\n", cwd);
		exit(0);
	}
	else if (!ft_strcmp(cmd->comd, "env"))
	{
		i = 0;
		while (heart->env[i])
		{
			printf("%s\n", heart->env[i]);
			i++;
		}
		exit(0);
	}
}
