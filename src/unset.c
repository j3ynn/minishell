/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:14:50 by jbellucc          #+#    #+#             */
/*   Updated: 2025/10/25 18:26:52 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_env(char **envp)
{
	int	count;

	count = 0;
	while (envp[count])
		count++;
	return (count);
}

int	find_env_index(char **envp, const char *key)
{
	int		i;
	size_t	key_len;

	key_len = strlen(key);
	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static void	shift_env(char **envp, int index)
{
	while (envp[index])
	{
		envp[index] = envp[index + 1];
		index++;
	}
}

int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	**unset_env_var(char **envp, const char *key, t_heart *heart)
{
	char	**new_env;
	int		count;
	int		index;

	new_env = realloc(envp, sizeof(char *) * count);
	count = count_env(envp);
	index = find_env_index(envp, key);
	if (!is_valid_identifier(key))
	{
		ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd((char *)key, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		heart->last_status = 1;
		return (envp);
	}
	if (index == -1)
		return (envp);
	free(envp[index]);
	shift_env(envp, index);
	if (!new_env)
		return (envp);
	return (new_env);
}
