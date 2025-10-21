#include "../minishell.h"

int	handle_quotes(char *str)	// Questa funzione controlla se ci sono virgolette aperte ma non chiuse correttamente nella stringa.
{									//se le virgolette non sono chiuse correttamente il comando e' sbagliato
	char	quote;
	bool	in_quotes;
	int 	i;

	i = 0;
	in_quotes = false;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (!in_quotes)
			{
				in_quotes = true;
				quote = str[i];
			}
			else if(str[i] == quote)
			{
				in_quotes = false; 
			}
		}
		i++;
	}
	return (in_quotes);
}

void	single_quote(char *str, int *i, char *result, int *j)	//non interpreta ne espande nulla, quando stampi tra "'" non le stampa
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		result[(*j)++] = str[*i];
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
}

void	double_quote(char *str, int *i, char *result, int *j, t_heart *heart)	//se ci sono le doppie espande e non stampa le quote
{
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$' && str[*i + 1])
		{
			if (str[*i + 1] == '?' || ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
				expand_var(str, i, result, j, heart);
			else
			{
				result[(*j)++] = str[*i];
				(*i)++;
			}
		}
		else
		{
			result[(*j)++] = str[*i];
			(*i)++;
		}
	}
	if (str[*i] == '"')
		(*i)++;
}

char	*quote_menage(char *token, t_heart *heart)	//gestisce tutti i casi richiamando la funzione sopra
{
	char	*result;
	int 	i;
	int 	j;

	result = malloc(ft_strlen(token) * 10);  // Buffer largo per espansioni
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] == '\'')
			single_quote(token, &i, result, &j);
		else if (token[i] == '"')
			double_quote(token, &i, result, &j, heart);
		else if (token[i] == '$' && token[i + 1])
		{
			if (token[i + 1] == '?' || ft_isalnum(token[i + 1]) || token[i + 1] == '_')
				expand_var(token, &i, result, &j, heart);
		}
		else
		{
			result[j++] = token[i];
			i++;
		}
	}
	result[j] = '\0';
	return (result);
}
