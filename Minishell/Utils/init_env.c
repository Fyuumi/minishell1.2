/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:53:20 by cdenaux           #+#    #+#             */
/*   Updated: 2026/05/20 16:04:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var	*ft_new_node(const char *key, const char *value)
{
	t_env_var	*node;

	node = malloc(sizeof(t_env_var));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (value == NULL)
		node->value = NULL;
	else
		node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

char	**ft_env_to_envp(t_env *env)
{
	char		**envp;
	t_env_var	*current;
	char		*tmp;
	int			i;

	i = 0;
	envp = malloc(sizeof(char *) * ft_listsizes(env) + 1);
	if (!envp)
		return (NULL);
	current = env->vars;
	while (current)
	{
		tmp = ft_strjoin(current->key, "=");
		if (!tmp)
			return (NULL);
		envp[i] = ft_strjoin(tmp, current->value);
		free(tmp);
		if (!envp)
			return (NULL);
		i++;
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}
t_env_var	*ft_new_env_var(char *envp)
{
	t_env_var	*node;
	char		*sep;

	node = malloc(sizeof(t_env_var));
	if (!node)
		return (NULL);
	sep = ft_strchr(envp, '=');
	if (sep)
	{
		node->key = ft_substr(envp, 0, sep - envp);
		node->value = ft_strdup(sep + 1);
	}
	else
	{
		node->key = ft_strdup(envp);
		node->value = NULL;
	}
	node->next = NULL;
	if (!node->key)
	{
		free(node->value);
		free(node);
		return (NULL);
	}
	return (node);
}

/*Appends a node at the end of the list.*/

void	ft_append_env_var(t_env *env, t_env_var *node)
{
	t_env_var	*current;

	if (!env->vars)
	{
		env->vars = node;
		return ;
	}
	current = env->vars;
	while (current->next)
		current = current->next;
	current->next = node;
}

/*Converts char **envp (from main) into a t_env
envp_array is left NULL : rebuilt on demand before execve() !!!! ***** Nope,
	need to change that later
Returns NULL on malloc failure.*/

t_env	*ft_init_env(char **envp)
{
	t_env		*env;
	t_env_var	*node;
	int			i;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->vars = NULL;
	env->envp_array = NULL;
	int j = 0;
	while (envp[j])
		j++;
	env->envp_array = malloc(sizeof(char *) * j);
	for (int k = 0; k < j; k++)
		env->envp_array[k] = ft_strdup(envp[k]);
	i = 0;
	while (envp[i])
	{
		node = ft_new_env_var(envp[i]);
		if (!node)
		{
			// free_env(env) **must be coded**
			free(env);
			return (NULL);
		}
		ft_append_env_var(env, node);
		i++;
	}
	return (env);
}
