#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	get_quoted_len(char *str, int start)	//calcola la lunghezza delle quote (",') incluse le quote stesse
{
	char	quote;
	int		i;

	quote = str[start];
	i = start + 1;
	while (str[i] && str[i] != quote)
		i++;
	if (str[i] == quote)
		i++;
	return (i - start);
}

int	get_operator_len(char *str, int start)	//calcola la lunghezza di un operatore
{
	if ((str[start] == '>' && str[start + 1] == '>') ||
		(str[start] == '<' && str[start + 1] == '<'))
		return (2);
	return (1);
}

int	get_normal_len(char *str, int start)	//calcola la lunghezza di una parola normale
{												//finchè non incontra \0, tab, |, << ...
	int	i;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != '\t' &&
		   str[i] != '|' && str[i] != '<' && str[i] != '>' &&
		   str[i] != '\'' && str[i] != '"')
		i++;
	return (i - start);
}

int	get_manage(char *str, int start)	//gestisce tutte le funzioni sopra e lo richiamiamo in get_word
{											//quindi se incotra operatori richiama get_operator_len ecc...
	if (str[start] == '\'' || str[start] == '"')
		return (get_quoted_len(str, start));
	else if (str[start] == '|' || str[start] == '<' || str[start] == '>')
		return (get_operator_len(str, start));
	else
		return (get_normal_len(str, start));
}

