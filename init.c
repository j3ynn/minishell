/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:16:56 by jbellucc          #+#    #+#             */
/*   Updated: 2025/08/06 19:14:30 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_heart(t_heart *heart, char **envp)
{
	if (!heart || !envp)
    {
        write(2, "Error: Invalid parameters in init_heart\n", 40);
        exit(1);
    }
	heart->env = init_envp(envp);
	heart->input_line = NULL;
	heart->num_comds = 0;
	heart->pipes = 0;
	heart->has_pipes = false;
	heart->stdin_backup = 0;
	heart->stdout_backup = 0;
	
}
int arraylen(char **array){
	if (!array)
		return 0;
	int i = 0;
	while (array[i] != NULL)
		i++;
	printf("il numero di variabili e' %d\n", i);
	return i;
}
char **init_envp(char **envp){
	int len = arraylen(envp);
	char **new_env = malloc(sizeof(char *) * (len + 1));
	int i = 0;
	if (!new_env)
    {
        perror("malloc failed in copy_environment");
        exit(1);
    }
	while (envp[i])
    {
        new_env[i] = ft_strdup(envp[i]);
        if (!new_env[i])
        {
            //free_env_array(new_env, i);
            exit(1);
        }
        i++;
    }
    new_env[i] = NULL;
	return (new_env);
}