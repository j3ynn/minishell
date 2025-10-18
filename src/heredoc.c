#include "../minishell.h"

int create_heredoc(t_heart *heart)
{
    int     pipefd[2];
    char    *line;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return (1);
    }

    while (1)
    {
        line = readline("> ");
        if (!line) // EOF (Ctrl-D)
            break;

        if (!ft_strcmp(line, heart->heredoc.delimiter))
        {
            free(line);
            break;
        }
        write(pipefd[1], line, strlen(line));
        write(pipefd[1], "\n", 1);
        free(line);
    }
    close(pipefd[1]); // chiudo scrittura, il reader leggerà i dati
    dup2(pipefd[0], STDIN_FILENO); // rimpiazzo stdin con l’heredoc
    close(pipefd[0]);
    return (0);
}

