#include "minishell.h"

static int  name_compare(t_list *lst, char *str)
{
    t_env   *ptr;

    ptr = (t_env *)lst->content;
    if (!ft_strncmp(str, ptr->name, ft_strlen(ptr->name) + 1))
        return (1);
    return (0);
}

static void unset_var(t_list **head, char *str)
{
    t_list  **crr;
    t_list  *next;
    int     i;

    i = 0;
    crr = head;
    while (*crr)
    {
        if (name_compare(*crr, str))
        {
            next = (*crr)->next;
            ft_lstdelone(*crr, &delete_entry);
            *crr = next;
            break ;
        }
        i++;
        crr = &(*crr)->next;
    }
}

static int  is_valid(char *s)
{
    while (s && *s)
    {
        if (!ft_isalnum(*s))
            return (0);
        s++;
    }
    return (1);
}

void    delete_entry(void *lst)
{
    t_env   *cnt;

    cnt = (t_env *)(lst);
    if (cnt->name)
        free(cnt->name);
    if (cnt->value)
        free(cnt->value);
    free(cnt);
}

void    builtin_unset(t_list **head, t_core *data)
{
    int i;

    if (!data)
        return ;
    i = 1;
    while (ft_strlen(data->tkn[i]))
    {
        if (is_valid(data->tkn[i]))
            unset_var(head, data->tkn[i]);
        else
        {
            printf("unset : \'%s\': not a valid identifier!\n", data->tkn[i]);
            sandro_error_print(head, NULL, 1);
            break ;
        }
        i++;
    }
    return ;
}