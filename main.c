#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <readline/history.h>
#include "minishell.h"

int main(void)
{
    char *prompt;

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

        printf("Questo è il tuo comando %s \n", prompt);
        add_history(prompt);
        free(prompt);
    }
    return 0;
}

