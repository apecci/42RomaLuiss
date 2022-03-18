/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:48:51 by apecci            #+#    #+#             */
/*   Updated: 2022/03/14 15:48:53 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_env
{
	char	*name;
	char	*value;
}		t_env;

typedef struct s_core
{
	int		err;
	int		redin;
	int		redout;
	int		appin;
	int		appout;
	int		fdin;
	int		fdout;
	int		fd;
	int		pin;
	int		pout;
	int		pipe;
	int		pipen;
	int		*fdpipe;
	char	**tkn;
	char	*inname;
	char	*outname;
}		t_core;

//utils.c
int		get_next_line(int fd, char **line);

//utils1.c
size_t	gnl_strlen(const char *s, int flag);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

//utils2.c
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		is_new_lst(t_list **head, char *name, char *value);

//utils3.c
t_list	*ft_lstlast(t_list *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//utils4.c
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalnum(int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s);

//utils5.c
int		ft_lstsize(t_list *lst);
int		sandro_error_print(t_list **head, char *str, int n);
void	ft_putendl_fd(char *s, int fd);
void	sandro_cerror(t_list **head, char *s1, char *s2, int n);

//utils6.c
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

//utils_env.c
int		init_env(t_list **head, char **envp);
int		init_env2(t_list **head, char *name, char *value);

//utils_env2.c
int		ft_atoi(const char *nptr);
void	free_env(t_list **head, int flg);
void	envexp(char **m, t_list **head);

//utils_env3.c
void	varexp(char **m, int i, t_list **head);

//utils_env4.c
char	*envget(t_list *head, char *str);

//utils_sandro.c
char	*get_pro(t_list *head);
void	sandrolete(void *lst);
void	sandro_quit(t_list **env, t_list **c);
void	comandelete(void *lst);

//utils_sandro1.c
void	in_scan(char *in, t_list **head, t_list **lsthead);

//utils_token.c
char	**token_cutter(char *str, t_list **head);
void	token_spacer(char **line);

//utils_token1.c
void	mfiller(char **m, char *start, char *end, int i);

//utils_token2.c
int		checktokin(t_core *cnt, int i);
int		checktokout(t_core *cnt, int i);

//utils_token3.c
void	delete_cmd(void *lst);
void	delete_first(t_list **head);

//utils_sig.c
void	in_sig(void);
void	block_sig_cmd(void);

//utils_arguments.c
int		arg_reader(t_list **lsthead, int i, int tok);

//utils_exe.c
int		ft_execute(t_list **head, t_list **lsthead);

//utils_pipe.c
int		init_pipes(t_list **lsthead);
int		check_builtin(t_core *data, int len);
void	close_pipe(t_core *data);
void	close_pipes(t_core *data);

//utils_red.c
int		ft_redirect(t_list **head, t_core *cnt);
int		ft_close_redirect(t_core *cnt);

//utils_fd.c
void	fd_in(t_list **head, t_core *cnt);

//utils_fd1.c
void	exit_fd(int fd, char *str);
void	stop_fd(int sig);

//utils_builtin.c
int		builtin_exe(t_core *data, t_list **head, int len, t_list **lsthead);

//utils_exit.c

#endif
