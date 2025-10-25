/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:29:40 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 16:33:49 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_value(t_heart *heart, char *var_name)
{
	int		i;
	char	*equal_pos;
	int		name_len;

	i = 0;
	while (heart->env[i])
	{
		equal_pos = ft_strchr(heart->env[i], '=');
		if (equal_pos)
		{
			name_len = equal_pos - heart->env[i];
			if (ft_strncmp(heart->env[i], var_name, name_len) == 0
				&& var_name[name_len] == '\0')
				return (equal_pos + 1);
		}
		i++;
	}
	return (NULL);
}

static void	expand_var2(t_heart *heart, char *result, int *j, int *i)
{
	char	*exit_code;
	int		k;

	exit_code = ft_itoa(heart->last_status);
	k = 0;
	while (exit_code[k])
	{
		result[(*j)++] = exit_code[k];
		k++;
	}
	free(exit_code);
	(*i)++;
}

void	expand_var(char *str, int *i, char *result, int *j)
{
	t_heart	*heart;
	char	name_var[MAX_VAR_LENGTH];
	char	*value;
	int		k;

	(*i)++;
	if (str[*i] == '?')
	{
		expand_var2(heart, result, j, i);
		return ;
	}
	k = 0;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		name_var[k++] = str[*i];
		(*i)++;
	}
	name_var[k] = '\0';
	value = env_value(heart, name_var);
	if (value)
	{
		k = 0;
		while (value[k])
			result[(*j)++] = value[k++];
	}
}
