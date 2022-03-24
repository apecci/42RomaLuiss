#include "minishell.h"

void    pipe_exe(char *name, t_list **head, t_core *data)
{
    int in;
    int err;

    err = 0;
    if (data->pipe < 1)
        err = execve(name, get_argv(data, name), env_export(head));
    else
    {
        in = data->pipen * 2;
        if (!data->redout && !data->appout && data->pipen != data->pipe)
            dup2(data->fdpipe[in + 1], STDOUT_FILENO);
        if (!data->redin && data->appin && data->pipen > 0)
            dup2(data->fdpipe[in - 2], STDIN_FILENO);
        err = execve(name, get_argv(data, name), env_export(head));
        close_pipes(data);
    }
    if (err)
        exit(errno);
}