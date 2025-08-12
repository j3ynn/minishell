#include "../minishell.h"

int	count_args(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "<") == 0 || ft_strcmp(tokens[i], ">") == 0 ||
			ft_strcmp(tokens[i], ">>") == 0 || ft_strcmp(tokens[i], "<<") == 0)
		{
			i++;
			if (tokens[i])
				i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}
int	count_pipes(char *str)
{
	int		i = 0;
	int		count_pipes_out = 0;
	bool	in_quotes = false;
	char	closed_quote = 0;

	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"'))
		{
			if (!in_quotes)
			{
				in_quotes = true;
				closed_quote = str[i];
			}
			else if (str[i] == closed_quote)
			{
				in_quotes = false;
				closed_quote = 0;
			}
		}
		else if (str[i] == '|' && !in_quotes)
			count_pipes_out++;
		i++;
	}
	return (count_pipes_out + 1);
}
