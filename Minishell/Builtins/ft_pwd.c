/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:42:58 by cdenaux           #+#    #+#             */
/*   Updated: 2026/03/05 18:45:14 by cdenaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Shows the full path of the folder you're currently in
subject says no option needed (-L nor -P)
should display: /home/user/my_directory 
uses authorized function getcwd()*/

#include "minishell.h"

int ft_pwd(void)
{
    char cwd[4096];

    if (getcwd(cwd, sizeof(cwd)))
    {
        write(STDOUT_FILENO, cwd, ft_strlen(cwd));
        write(STDOUT_FILENO, "./", 2);
        return (0);
    }
    //print_error("pwd", NULL, strerror(errno)); => needs print_error function
    //strerror is an authorized function
    return (1);
}