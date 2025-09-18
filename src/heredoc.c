#include "../minishell.h"

int	create_heredoc(t_heart *heart)
{
	char	tmpl[] = "/tmp/minishell_hdoc_XXXXXX";
	char	*line;
	size_t	n;
	ssize_t	r;
	int		fd;

	if (!heart)
		return (-1);
	fd = mkstemp(tmpl);
	if (fd == -1)
	{
		perror("mkstemp");
		return (-1);
	}
	heart->heredoc.temp_file = ft_strdup(tmpl);
	line = NULL;
	n = 0;
	while (1)
	{
		write(1, "> ", 2);
		r = getline(&line, &n, stdin);
		if (r <= 0)
			break ;
		if (r > 0 && line[r - 1] == '\n')
			line[r - 1] = '\0';
		if (!ft_strcmp(line, heart->heredoc.delimiter))
			break ;
		write(fd, line, strlen(line));
		write(fd, "\n", 1);
	}
	free(line);
	close(fd);
	return (0);
}

void	cleanup_heredoc(t_heart *heart)
{
	if (!heart || !heart->heredoc.temp_file)
		return ;
	unlink(heart->heredoc.temp_file);
	free(heart->heredoc.temp_file);
	heart->heredoc.temp_file = NULL;
}
