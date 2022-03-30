#include "minishell.h"

static int  comparation(char *one, char *two)
{
    int i;
    i = 0;
    while (one && two)
    {
        if (one[i] > two[i])
            return (1);
        else if (one[i] < two[i])
            return (0);
            else if (one[i] == two[i])
                i++;
    }
    return (0);
}

static void swapple(t_env **lst, int n)
{
    t_env   *tmp;
    int     swap;
    int     run;

    swap = 1;
    while (swap)
    {
        swap = 0;
        run = 0;
        while (run < n - 1)
        {
            if (comparation(lst[run]->name, lst[run + 1]->name))
            {
                tmp = lst[run];
                lst[run] = lst[run + 1];
                lst[run + 1] = tmp;
                swap = 1;
            }
            run++;
        }
    }
}

t_env   **sort_env(t_list **head)
{
    t_list  *lst;
    t_env   **ret;
    int     i;

    i = 0;
    ret = ft_calloc(get_env_n(head) + 1, sizeof(t_env *));
    if (!ret)
        return (NULL);
    lst = *head;
    while (lst)
    {
        ret[i] = (t_env *)(lst->content);
        i++;
        lst = lst->next;
    }
    ret[i] = NULL;
    swapple(ret, get_env_n(head));
    return (ret);
}