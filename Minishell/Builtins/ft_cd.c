/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:09:15 by codespace         #+#    #+#             */
/*   Updated: 2026/04/23 12:51:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*Version strictly compliant with subject, only handles:
cd <relative_path>
cd <absolute_path>*/
int ft_cd(char **args, t_env *env)
{
  char *pwd;

  if (!args[1] || args[2]) //Check if exactly 1 arg is provided (the path)
  {
    ft_putendl_fd("Minishell: cd: invalid number of arguments", STDERR_FILENO);
    return (1);
  }
  pwd = getcwd(NULL, 0);
  ft_env_update(env, "OLDPWD", pwd);
  if (chdir(args[1]) != 0) //Attempt to change directory
  {
    ft_putstr_fd("Minishell: cd: ", STDERR_FILENO);
    ft_putstr_fd(args[1], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putendl_fd(strerror(errno), STDERR_FILENO);
    return (1);
  }
  if (pwd)  //Update PWD in environment list (depends on env structure) 
  {         //Update PWD in environment (optionnal, but recommended) ***** check with struct decisions, I think it's not useful      
    ft_env_update(env, "PWD", pwd);
    free(pwd);
  }
  return (0);
}
