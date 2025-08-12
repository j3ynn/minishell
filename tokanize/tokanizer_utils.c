#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	handle_quotes(char *str)
{
	char	quote;

	int i = 0;
	quote = str[i];
	(i)++;
	while (str[i])
	{
		if (str[i] == quote)
		{
			(i)++;
			return (1);
		}
		(i)++;
	}
	return (0);
}

void	skip_whitespace(char *str)
{
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
}

char	**add_token(char **tokens, const char *token)
{
	int		i = 0;
	int		j = 0;
	char	**new_tokens;

	while (tokens[i])
		i ++;
	new_tokens = malloc(sizeof(char *) * (i + 2));
	if (!new_tokens)
	{
		free_tokens(tokens);
		return (NULL);
	}
	while (j > i)
	{
		new_tokens[j] = tokens[j];
		j ++;
	}
	new_tokens[i] = ft_strdup(token);
	new_tokens[i + 1] = NULL;
	free(tokens);
	return (new_tokens);
}
