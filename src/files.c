#include "../minishell.h"

int open_input_file(t_comand *cmd, t_heart *heart)
{
    int fd;

    if (!cmd->input_file)
        return -1;

    if (!ft_strcmp(cmd->input_file, "HEREDOC"))
    {
        // heredoc: create_heredoc già fa dup2() su STDIN,
        // quindi qui non apriamo niente e ritorniamo -1
        create_heredoc(heart);
        return -1;
    }

    fd = open(cmd->input_file, O_RDONLY);
    if (fd == -1)
        perror("open");
    return fd;
}

int	open_output_file(t_comand *cmd)
{
	int	flags;
	int	fd;

	if (!cmd || !cmd->output_file)
		return (-1);
	flags = O_WRONLY | O_CREAT;
	if (cmd->redirection)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(cmd->output_file, flags, 0644);
	if (fd == -1)
		fprintf(stderr, "minishell: %s: %s\n", cmd->output_file, strerror(errno));
	return (fd);
}
