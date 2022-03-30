#include "minishell.h"

void    builtin_pwd(t_list **head)
{
    char    *str;

    str = envget(*head, "PWD");
    if (str)
        printf("%s\n", str);
    sandro_error_print(head, NULL, 0);
}