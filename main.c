/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: je <je@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:59:23 by jbellucc          #+#    #+#             */
/*   Updated: 2025/08/12 16:28:10 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *prompt = NULL;
	t_heart heart;
	init_heart(&heart, envp);
	(void) argc;
	(void) argv;
	while (1)
	{
		prompt = readline("<sushell ");

		if (prompt == NULL)
			break;  // Esce dal ciclo se EOF o errore
	if (prompt[0] == '\0')
	{
		free(prompt);
		continue;
	}
		if (ft_strncmp(prompt, "exit", 4) == 0 && prompt[4] == '\0')
		{
			printf("Ciaone\n");
			free(prompt);
			return 0;
		}
		heart.input_line = prompt;
		printf("Questo è il tuo comando %s \n", prompt);
		add_history(prompt);
		printf("handle_quotes = %d (dovrebbe essere 1)\n", handle_quotes(prompt));

		free(prompt);
	}
	return 0;
}
