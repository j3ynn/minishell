/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:59:23 by jbellucc          #+#    #+#             */
/*   Updated: 2025/08/06 19:15:03 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char *prompt = "ciao";
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
        free(prompt);
    }
    return 0;
}

