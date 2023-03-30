/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:49:16 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 14:55:58 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

void	ft_stacks_init(t_stacks *s, int ac)
{
	s->size = ac - 1;
	s->a = ft_calloc(s->size, sizeof(int));
	s->b = ft_calloc(0, sizeof(int));
	s->a_size = s->size;
	s->b_size = 0;
}

void	ft_mmm_init(t_mmm *m)
{
	m->max = 0;
	m->med = 0;
	m->min = 0;
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_mmm		*m;

	m = ft_calloc(1, sizeof(t_mmm));
	ft_mmm_init(m);
	if (ac < 2)
		return (0);
	if (ac == 2)
		ft_get_stack(av[1], &stacks);
	else
		ft_multiarg_stack(ac, av, &stacks);
	if (!ft_sorted(&stacks))
		ft_sorter(&stacks, m);
	if (!ft_sorted(&stacks))
		ft_rot_sort(&stacks);
	free(stacks.a);
	free(stacks.b);
	return (0);
}
