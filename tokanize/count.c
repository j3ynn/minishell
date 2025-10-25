/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:50:31 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 16:52:31 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirection(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, ">>") == 0 || ft_strcmp(token, "<<") == 0);
}

int	arraylen(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}

int	count_args(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "<") == 0 || ft_strcmp(tokens[i], ">") == 0
			|| ft_strcmp(tokens[i], ">>") == 0
			|| ft_strcmp(tokens[i], "<<") == 0)
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

static void	count_pipe2(char c, bool *in_quotes, char *closed_quote)
{
	if (c == '\'' || c == '"')
	{
		if (!(*in_quotes))
		{
			*in_quotes = true;
			*closed_quote = c;
		}
		else if (c == *closed_quote)
		{
			*in_quotes = false;
			*closed_quote = 0;
		}
	}
}

int	count_pipes(char *str)
{
	int		i;
	int		count_pipes_out;
	bool	in_quotes;
	char	closed_quote;

	i = 0;
	count_pipes_out = 0;
	in_quotes = false;
	closed_quote = 0;
	while (str[i])
	{
		count_pipe2(str[i], &in_quotes, &closed_quote);
		if (str[i] == '|' && !in_quotes)
			count_pipes_out++;
		i++;
	}
	return (count_pipes_out + 1);
}
