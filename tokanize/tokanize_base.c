#include "../minishell.h"

int	skip_whitespace(char *str)	//salta tutti gli spazi e tab in più nella stringa
{
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
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
	while (j < i)
	{
		new_tokens[j] = ft_strdup(tokens[j]);
		j ++;
	}
	new_tokens[i] = ft_strdup(token);
	new_tokens[i + 1] = NULL;
	free_tokens(tokens);
	return (new_tokens);
}

char	*get_word(char *str, int start)	//estrae una parola o un token dalla stringa di input
{											//tutte le funzioni che ho richiamato stanno in tokanize_utils
	int		len;
	int		i;
	char	*word;

	len = get_manage(str, start);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**process_input(char *input)	//prende l'input e lo spezza in token
{
	char	**tokens;
	char	*word;
	int		i;

	tokens = malloc(sizeof(char *) * 1);
	if (!tokens)
		return (NULL);
	tokens[0] = NULL;
	i = 0;
	while (input[i])
	{
		i += skip_whitespace(input + i);
		if (!input[i])
			break;
		word = get_word(input, i);
		if (!word)
		{
			free_tokens(tokens);
			return (NULL);
		}
		tokens = add_token(tokens, word);
		free(word);
		if (!tokens)
			return (NULL);
		i += get_manage(input, i);
	}
	return (tokens);
}


