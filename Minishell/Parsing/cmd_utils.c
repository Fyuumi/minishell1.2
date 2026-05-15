/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:59:48 by codespace         #+#    #+#             */
/*   Updated: 2026/05/15 14:00:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*From pipex project to get cmd path*/

char	*get_path(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*join_check_path(char *dir, char *cmd)
{
	char	*full_path;
	char	*path_cmd;

	full_path = ft_strjoin(dir, "/");
	if (!full_path)
		return (NULL);
	path_cmd = ft_strjoin(full_path, cmd);
	free(full_path);
	if (!path_cmd)
		return (NULL);
	if (access(path_cmd, X_OK) == 0)
		return (path_cmd);
	free(path_cmd);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_var;
	char	**paths;
	size_t	i;
	char	*cmd_path;

	if (!cmd || !envp)
		return (NULL);
	path_var = get_path(envp);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	i = 0;
	cmd_path = NULL;
	while (paths[i] && !cmd_path)
	{
		cmd_path = join_check_path(paths[i], cmd);
		i++;
	}
	free_strtab(paths);
	return (cmd_path);
}

void	ft_run_execve(char **argv, t_env *env)
{
	char	*cmd_path;

	if (!argv || !argv[0])
		exit(0);
	/*If user wrote a path (e.g. /bin/ls or ./a.out), do NOT search PATH*/
	if (ft_strchr(argv[0], '/'))
	{
		execve(argv[0], argv, env->envp_array);
		perror(argv[0]); // prints "No such file", "Permission denied", ...
		if (errno == ENOENT)
			exit(127);
		exit(126);
	}
	/*Otherwise search PATH*/
	cmd_path = get_cmd_path(argv[0], env->envp_array);
	if (!cmd_path)
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(127);
	}
	execve(cmd_path, argv, env->envp_array);
	perror(argv[0]); // execve failed (rare: e.g. permission denied on resolved path)
	free(cmd_path);
	exit(126);
}
