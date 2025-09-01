#include "../minishell.h"

int	redirection(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0 ||
			ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0);
}

char	**pipes_split(char *input, int num_cmds)
{
	char	**cmd_separ;
	int		cmd_idx;
	int		start;
	int		i;

	cmd_separ = malloc(sizeof(char *) * (num_cmds + 1));
	cmd_idx = 0;
	start = 0;
	i = 0;
	if (!cmd_separ)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '|')
		{
			cmd_separ[cmd_idx++] = ft_substr(input, start, i - start);
			start = i + 1;
			start += skip_whitespace(input + start);
		}
		i++;
	}
	cmd_separ[cmd_idx] = ft_substr(input, start, i - start);
	return (cmd_separ);
}

void	handle_redirections(t_comand *cmd, char **tokens, int *j, t_heart *heart)
{
	if (!tokens[*j + 1])
		return;
	if (ft_strcmp(tokens[*j], "<") == 0)
		cmd->input_file = ft_strdup(tokens[*j + 1]);
	else if (ft_strcmp(tokens[*j], ">") == 0)
	{
		cmd->output_file = ft_strdup(tokens[*j + 1]);
		cmd->redirection = false;
	}
	else if (ft_strcmp(tokens[*j], ">>") == 0)
	{
		cmd->output_file = ft_strdup(tokens[*j + 1]);
		cmd->redirection = true;
	}
	else if (ft_strcmp(tokens[*j], "<<") == 0)
	{
		ft_strlcpy(heart->heredoc.delimiter, tokens[*j + 1], 250);
		cmd->input_file = ft_strdup("HEREDOC");
	}
	(*j)++;
}

void	setup_command(t_comand *cmd, char **tokens, t_heart *heart)
{
	int	j;
	int	arg_idx;

	j = 0;
	arg_idx = 0;
	cmd->num_arg = count_args(tokens);
	cmd->args = malloc(sizeof(char *) * (cmd->num_arg + 1));
	if (!cmd->args)
		return ;
	while (tokens[j])
	{
		if (redirection(tokens[j]))
			handle_redirections(cmd, tokens, &j, heart);
		else
		{
			if (arg_idx == 0)
				cmd->comd = ft_strdup(tokens[j]);
			cmd->args[arg_idx++] = ft_strdup(tokens[j]);
		}
		j++;
	}
	cmd->args[arg_idx] = NULL;
}

void	create_single_command(t_heart *heart, char *cmd_str, int cmd_index)
{
	char		**tokens;
	t_comand	*cmd;

	tokens = process_input(cmd_str);
	if (!tokens)
		return ;
	cmd = &heart->comds[cmd_index];
	setup_command(cmd, tokens, heart);
	free_tokens(tokens);
}
