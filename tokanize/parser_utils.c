#include "../minishell.h"

int	redirection(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0 ||
			ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0);
}

char	**pipes_split(char *input, int num_cmds)	//lavora nell input e se ci sono comandi separati da pipe li spezza
{														//in un array di stringhe ed ogniuna conterrà un singolo comando suca
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
		if (input[i] == '"' || input[i] == '\'')
			i += get_quoted_len(input, i);
		if (input[i] == '|')
		{
			cmd_separ[cmd_idx++] = ft_substr(input, start, i - start);
			start = i + 1;
			start += skip_whitespace(input + start);
		}
		i++;
	}
	cmd_separ[cmd_idx] = ft_substr(input, start, i - start);
	cmd_separ[cmd_idx+1] = NULL;
	return (cmd_separ);
}

void	handle_redirections(t_comand *cmd, char **tokens, int *j, t_heart *heart)	//da effetivamente un valore ai simboli di redirezione
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
	(*j) += 2;
}

void	setup_command(t_comand *cmd, char **tokens, t_heart *heart)	//prepara la struttura cmd a poter eseguire un comando
{																		//estrae in comando, estrae gli argomenti, gestisce le redirezioni
	int		j;																	//salva tutto dentroa t_comand
	int		arg_idx;
	char	*quote;

	j = 0;
	arg_idx = 0;
	cmd->num_arg = count_args(tokens);
	if (cmd->num_arg == 0)
		return;
	cmd->args = malloc(sizeof(char *) * (cmd->num_arg + 1));
	if (!cmd->args)
		return ;
	while (tokens[j])
	{
		if (redirection(tokens[j]))
			handle_redirections(cmd, tokens, &j, heart);
		else
		{
			quote = quote_menage(tokens[j]);
			if (arg_idx == 0)
				cmd->comd = ft_strdup(quote);
			cmd->args[arg_idx++] = quote;
			j++;
		}
	}
	cmd->args[arg_idx] = NULL;
}

void	create_single_command(t_heart *heart, char *cmd_str, int cmd_index)	//prepara un singolo comando prima di eseguirlo
{																				//ES capisce cosa vuoi fare, segna tutto e in fine esegue
	char		**tokens;
	t_comand	*cmd;

	tokens = process_input(cmd_str);
	if (!tokens || !tokens[0])
		return ;
	cmd = &heart->comds[cmd_index];
	setup_command(cmd, tokens, heart);
	free_tokens(tokens);
}

int	parse_input(t_heart *heart, char *input)	//analizza tutto l'input, divide in più comandi, gestisce le pipe e analizza le strutture
{
	char	**cmd_strs;
	int		i;

	if (!input || !*input)
		return (-1);
	if (handle_quotes(input))
		return (-1);
	heart->num_comds = count_pipes(input);
	heart->has_pipes = (heart->num_comds > 1);
	heart->input_line = ft_strdup(input);
	init_comand(heart, heart->num_comds);
	cmd_strs = pipes_split(input, heart->num_comds);
	if (!cmd_strs)
		return (-1);
	i = 0;
	while (i < heart->num_comds)
	{
		create_single_command(heart, cmd_strs[i], i);
		i++;
	}
	free_tokens(cmd_strs);
	return (0);
}
