/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:49:53 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:04:04 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stacks
{
	int	*a;
	int	a_size;
	int	*b;
	int	b_size;
	int	size;
}				t_stacks;

typedef struct s_rot
{
	int	*ra;
	int	*rra;
	int	*rb;
	int	*rrb;
	int	*least;
	int	*scheme;
}				t_rot;

typedef struct s_mmm
{
	int	min;
	int	max;
	int	med;
}				t_mmm;

//INIT
void	ft_stacks_init(t_stacks *stacks, int ac);
void	ft_mmm_init(t_mmm *m);
void	ft_multiarg_stack(int ac, char **av, t_stacks *s);
void	ft_get_stack(char *av, t_stacks *s);

//GENERAL
void	swap(int *stack, char c);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate(int *stack, int size, char c);
void	revrot(int *stack, int size, char c);
void	ft_rr(t_stacks *s);
void	ft_rrr(t_stacks *s);
void	ft_ss(t_stacks *stacks);

//MEMORY
void	*ft_realloc(void *data, size_t nmemb, size_t size);
int		*ft_intcpy(void *src, int size);

//SORTS
void	ft_sorter(t_stacks *s, t_mmm *m);
void	ft_sort2(int *stack, char c);
void	ft_sort3(int *stack, int size, char c);
void	ft_sort5(t_stacks *stacks);
void	ft_multisort(t_stacks *stacks, t_mmm *m);
void	ft_indexing(t_stacks *stacks, t_rot *moves);
void	ft_a_indexing(t_stacks *s, int index, t_rot *moves);
void	ft_get_and_convert_index(t_stacks *s);
void	ft_median(t_stacks *s, t_mmm *m);
void	ft_best_moves(t_stacks *s, t_rot *moves);
int		ft_elem_to_move(t_stacks *s, t_rot *moves);
void	ft_move(t_stacks *s, t_rot *mv);

//SCHEMES
void	ft_scheme0(t_stacks *s, t_rot *mv, int index);
void	ft_scheme1(t_stacks *s, t_rot *mv, int index);
void	ft_scheme2(t_stacks *s, t_rot *mv, int index);
void	ft_scheme3(t_stacks *s, t_rot *mv, int index);

//CHECKERS
int		ft_sorted(t_stacks *s);
void	ft_rot_sort(t_stacks *s);
int		ft_check_doubles(int ac, char **av, int n);
int		ft_check_num(int ac, char **av, int n);

//UTILS
void	ft_swap(int *a, int *b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_strdigit(char *str);
int		ft_array_min(int *s, int size);
int		ft_array_max(int *s, int size);

#endif
