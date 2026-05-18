#include "minishell.h"

int ft_listsizes(void* content)
{
    t_env_var *temp;
    int count;

    temp = (t_env_var *)content;
    if (!content)
        return (0);
    count = 0;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return (count);
}
