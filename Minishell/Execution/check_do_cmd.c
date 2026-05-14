#include "minishell.h"

void	ft_ext_command(char *cmd_path, char **cmd_input, char **envp)
{
	pid_t	pid;
	int		status;

	if (cmd_path)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(cmd_path, cmd_input, envp);
			free(cmd_path);
			ft_free_strings(envp);
			exit(1);
		}
		ft_free_strings(envp);
		waitpid(pid, &status, 0);
	}
	else
	{
		write(STDOUT_FILENO, "command not found", 17);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	ft_check_do_cmd(char **cmd_input, t_env *env, t_cmd **cmd_list)
{
	char	**envp;
	char	*cmd_path;

	// compares your first word of input with the cmds,
	// if it matches it resolves
	if (!cmd_list)
		printf("no cmoomand found\n");
	if (ft_strncmp(cmd_input[0], "echo", (ft_strlen(cmd_input[0]) + 1)) == 0)
		ft_echo(cmd_input);
	else if (ft_strncmp(cmd_input[0], "cd", (ft_strlen(cmd_input[0]) + 1)) == 0)
		ft_cd(cmd_input, env);
	else if (ft_strncmp(cmd_input[0], "pwd", (ft_strlen(cmd_input[0])
				+ 1)) == 0)
		ft_pwd();
	else if (ft_strncmp(cmd_input[0], "unset", (ft_strlen(cmd_input[0])
				+ 1)) == 0)
		ft_unset(env, cmd_input[1]);
	else if (ft_strncmp(cmd_input[0], "export", (ft_strlen(cmd_input[0])
				+ 1)) == 0)
		ft_export(env, cmd_input[1]);
	else if (ft_strncmp(cmd_input[0], "exit", (ft_strlen(cmd_input[0])
				+ 1)) == 0)
		exit(1);
	else
	{
		envp = ft_env_to_envp(env);
		if (ft_strchr(cmd_input[0], '/'))
			cmd_path = ft_strdup(cmd_input[0]);
		else
			cmd_path = ft_get_cmd_path(cmd_input[0], envp);
		ft_ext_command(cmd_path, cmd_input, envp);
	}
	return ;
}
