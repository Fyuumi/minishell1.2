/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:33:14 by cdenaux           #+#    #+#             */
/*   Updated: 2026/05/11 16:20:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*function that displays a string
should behave differently if there's a "flag" -n
subject only mentions -n; not -e nor -E
-n => don't add a new line at the end
does't interpret "-n" as a flag => seen as string*/

#include "minishell.h"

static int is_flag_n(char *arg)
{ 
    if (!arg || arg[0] != '-')
        return (0);
    if (arg[1] == 'n')
        return (1);
    return (0);
}

void ft_writeforecho(char *str) // writes a string without the start "" and ends them after the secound one
{
    int i;

    i = 1;
    while(str[i] != '"' && str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return;
}

int ft_echo(char **args)
{
    int i;
    int flag_n;

    if (!args)
        return (0);
    i = 1;
    flag_n = 0;
    while(args[i] && is_flag_n(args[i]))
    {
        flag_n = 1;
        i++;
    }
    while(args[i])
    {
        if (args[i][0] == '"')        // if " found like in :i echo "hey"
            ft_writeforecho(args[i]);
        else
            ft_putstr_fd(args[i], 1);
        if (args[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (!flag_n)
        write(1, "\n", 1);
    return (0);
}
