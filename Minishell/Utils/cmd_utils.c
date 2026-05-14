/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:53:20 by cdenaux           #+#    #+#             */
/*   Updated: 2026/04/23 15:19:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_free_strings(char **args)
{
	int i;

	if (!args)
		return;
	i= 0;
	while(args[i])
		free(args[i++]);
	free(args);
}

 char	*ft_get_path(char **envp)
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

int	ft_is_exe(char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (0);
	if (S_ISDIR(st.st_mode))
		return (0);
	if ((st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) == 0)
		return (0);
	return (1);
}

 static char	*ft_join_check_path(char *dir, char *cmd)
 {
 	char	*full_path;
 	char	*path_cmd;

 	full_path = ft_strjoin(dir, "/");
 	if (!full_path)
 		return (NULL);
	path_cmd = NULL;
 	path_cmd = ft_strjoin(full_path, cmd);
 	free(full_path);
 	if (!path_cmd)
 		return (NULL);
 	if (ft_is_exe(path_cmd))
 		return (path_cmd);
 	free(path_cmd);
 	return (NULL);
 }
 
 char	*ft_get_cmd_path(char *cmd, char **envp)
 {
 	char	*path_var;
 	char	**paths;
 	size_t	i;
 	char	*cmd_path;

	path_var = ft_get_path(envp);
 	if (!path_var)
 		return (NULL);
 	paths = ft_split(path_var, ':');
 	if (!paths)
 		return (NULL);
 	i = 0;
 	cmd_path = NULL;
 	while (paths[i] && !cmd_path)
 	{
 		cmd_path = ft_join_check_path(paths[i], cmd);
 		i++;
 	}
 	ft_free_strings(paths);
	return (cmd_path);
 }

