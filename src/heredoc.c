#include "../minishell.h"

// Crea un heredoc e restituisce il file descriptor pronto per STDIN
int create_heredoc(t_heart *heart)
{
    char *line;
    int fd;

    // apri file temporaneo per scrivere il contenuto del heredoc
    fd = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("heredoc");
        return -1;
    }

    while (1)
    {
        line = readline("> ");   // prompt heredoc
        if (!line)   // Ctrl+D prima del delimitatore
        {
            ft_putstr_fd("warning: here-document delimited by end-of-file\n", 2);
            break;
        }
        if (ft_strcmp(line, heart->heredoc.delimiter) == 0)
        {
            free(line);
            break;   // trovato delimitatore → esco
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
    close(fd);

    // riapri il file temporaneo in lettura
    fd = open(".heredoc_tmp", O_RDONLY);
    if (fd == -1)
    {
        perror("heredoc");
        return -1;
    }

    // elimina subito il file: rimane leggibile finché fd resta aperto
    unlink(".heredoc_tmp");

    return fd; // fd sarà usato da dup2 in setup_redirections
}

