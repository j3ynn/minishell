#include "../minishell.h"

void	free_single_command(t_comand *cmd)
{
	int j = 0;

	if (cmd->comd)
		free(cmd->comd);
	if (cmd->args)
	{
		while (cmd->args[j])
			free(cmd->args[j++]);
		free(cmd->args);
	}
	if (cmd->input_file)
		free(cmd->input_file);

	if (cmd->output_file)
		free(cmd->output_file);
	cmd->comd = NULL;
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
}

void	free_commands(t_heart *heart)
{
	int i;

	if (!heart || !heart->comds)
		return;
	i = 0;
	while (i < heart->num_comds)
	{
		free_single_command(&heart->comds[i]);
		i++;
	}
	free(heart->comds);
	heart->comds = NULL;
	heart->num_comds = 0;
}

void	free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void free_env(char **env)
{
    int i = 0;
    if (!env)
        return;
    while (env[i])
    {
        free(env[i]);
        i++;
    }
    free(env);
}

void free_all(t_heart *heart)
{
    if (!heart)
        return;
    if(heart->env)
    {
	    free_env(heart->env);
	    heart->env = NULL;
    }
    if(heart->comds)
    {
	    free_commands(heart);
    }
    if(heart->pipes)
    {
	    free_pipes(heart);
	    heart->pipes = NULL;
    }
    if (heart->input_line)
    {
        free(heart->input_line);
	heart->input_line = NULL;
    }
}

