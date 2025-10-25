/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokanize_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:18:45 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 16:26:20 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

char	**add_token(char **tokens, const char *token)
{
	int		i;
	int		j;
	char	**new_tokens;

	i = 0;
	j = 0;
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

char	*get_word(char *str, int start)
{
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

static char	**process_input2(char *input, int *i, char **tokens)
{
	char	*word;

	word = get_word(input, *i);
	if (!word)
	{
		free_tokens(tokens);
		return (NULL);
	}
	tokens = add_token(tokens, word);
	free(word);
	if (!tokens)
		return (NULL);
	*i += get_manage(input, *i);
	return (tokens);
}

char	**process_input(char *input)
{
	char	**tokens;
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
			break ;
		tokens = process_input2(input, &i, tokens);
		if (!tokens)
			return (NULL);
	}
	return (tokens);
}
