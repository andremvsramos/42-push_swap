/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:56:21 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:02:58 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

//INIT
void		ft_stacks_init(t_stacks *stacks, int ac);
void		ft_multiarg_stack(int ac, char **av, t_stacks *s);
void		ft_get_stack(char *av, t_stacks *s);

//GENERAL
void		swap(int *stack);
void		ft_ss(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate(int *stack, int size);
void		revrot(int *stack, int size);
void		ft_rr(t_stacks *s);
void		ft_rrr(t_stacks *s);

//MEMORY
int			*ft_intcpy(void *src, int size);
void		*ft_realloc(void *data, size_t nmemb, size_t size);

//CHECKERS
int			ft_sorted(t_stacks *s);
int			ft_check_doubles(int ac, char **av, int n);
int			ft_check_num(int ac, char **av, int n);

//UTILS
int			ft_strdigit(char *str);

#endif
