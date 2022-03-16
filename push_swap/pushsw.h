/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushsw.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:52:19 by apecci            #+#    #+#             */
/*   Updated: 2021/10/27 15:52:21 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSW_H
# define PUSHSW_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# define MAX_STACK_LEN 10000

typedef struct s_struct
{
	int			*a;
	int			*b;
	int			*lis;
	int			*sub;
	int			len;
	int			ac;
	int			max;
	int			la;
	int			lb;
	char		*mosse;
	int			pos;
	int			x;
	int			mov;
	int			mass;
	int			indicatore;
}				t_struct;

typedef struct s_count
{
	int	j;
	int	index;
	int	max;
}				t_count;

typedef struct s_check
{
	int		*a;
	int		*b;
	char	*mosse;
	int		la;
	int		lb;
	int		ac;
}				t_check;

//UTILS1
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			integers(int ac, char **av);
int			ft_isdigit(char c);
void		double_search(t_struct *s);
void		ft_errors(int ac, char **av, t_struct *s);

size_t		ft_strlen(char *str);
char		*ft_strdup(char *s1);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		count_words(char *s, char c);
//UTILS2
char		**free_machine(char **s, size_t i);
size_t		word_len(char *str, char c);
char		**ft_split(char *s, char c);
int			ft_atoi(char *str);
void		puliscitutto(void **a, void *e);
void		ft_intcpy(int *stack, int *tmp, int len);
void		ft_ra(t_struct *s);

void		lis(t_struct *s);
void		ft_sa(t_struct *s);
void		ft_pb(t_struct *s);
int			check_ascending(t_check *s);
int			check_ascending_c(t_struct *s);

//UTILS3
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, int size);
void		ft_one(t_struct *s);
void		ft_sub(t_struct *s);

//GNL
int			get_next_line(char **line);
void		*ft_realloc(void *ptr, size_t size);
void		ft_rb(t_struct *s);
void		ft_rrb(t_struct *s);
void		ft_rra(t_struct *s);
void		ft_pa(t_struct *s);
void		ft_sb(t_struct *s);

//UTILS4
char		*ft_strjoin(char *s1, char *s2, t_struct *s);
void		ft_push_sub_a(t_struct *s);
void		ft_push_sub_b(t_struct *s);
void		runpapapam(int j, int i, t_struct *s);

//UTILS5
void		ft_ra1(t_struct *s);
void		ft_rb1(t_struct *s);
void		ft_rrb1(t_struct *s);
void		ft_rra1(t_struct *s);

int			ft_count_moves(t_struct *s, int pos, t_count *count);
int			ft_best_moves(t_struct *s, t_count *count);
void		ft_moves(t_struct *s, t_count *count);
void		ft_max(t_struct *s);
void		ft_rrr(t_struct *s);
void		ft_rr(t_struct *s);
void		ft_intimoves(t_count *count);

void		ft_av_copy(t_struct *s, char **av);
void		ft_init(t_struct *s);
void		parsing(t_struct *s, char **av);
void		you_make_me_make_moves(t_check *c, char *line);

//CHECKER
void		ft_pb_c(t_check *c);
void		ft_pa_c(t_check *c);
void		ft_sb_c(t_check *c);
void		ft_sa_c(t_check *c);
void		ft_ra_c(t_check *c);
void		ft_rb_c(t_check *c);
void		ft_rra_c(t_check *c);
void		ft_rrb_c(t_check *c);
void		ft_rr_c(t_check *c);
void		ft_rrr_c(t_check *c);
void		ft_ss_c(t_check *c);
void		ft_init_c(t_check *c);
void		double_search_c(t_check *c);
void		ft_av_copy_c(t_check *c, char **av);
void		parsing_c(t_check *c, char **av);
void		three_numbers(t_struct *s);
void		algoritmo(t_struct *s);
int			find_smallest(t_struct *s);
void		ranpapapam_volume_two(t_struct *s);
void		ft_free(t_struct *s);
void		ft_polka(t_struct *s);
void		ft_maurizio_sarri(t_struct *s);

#endif
