#include "minishell.h"

static int  dir_update(t_list **head)
{
    int     err;
    char    *new;

    err = 0;
    sandro_error_print(head, NULL, 0);
    err = init_env2(head, "OLDPWD", envget(*head, "PWD"));
    if (!err)
    {
        new = getcwd(NULL, 0);
        err = init_env2(head, "PWD", new);
        free(new);
    }
    return (err);
}

static char *tilde_check(t_list **head, char *str)
{
    if (!ft_strlen(str) || *str != '~' || !envget(*head, "HOME"))
        return (ft_strdup(str));
    str++;
    return (ft_strjoin(envget(*head, "HOME"), str));
}

int builtin_cd(t_list **head, t_core *data)
{
    int     err;
    char    *new;

    if (!head || !data || !data->tkn[1])
        return (1);
    if (!ft_strlen(data->tkn[1]))
        err = chdir(envget(*head, "HOME"));
    else
    {
        new = tilde_check(head, data->tkn[1]);
        err = chdir(new);
        if (new)
            free(new);
    }
    if (err)
        sandro_error_print(head, data->tkn[1], -1);
    else
    {
        err = dir_update(head);
        sandro_error_print(head, NULL, 0);
    }
    return (err);
}