/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:37:46 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 17:21:31 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*If its 2 elements and the first is higher than second, swap them.*/
void	ft_sort2(int *s, char c)
{
	if (s[0] > s[1])
		swap(s, c);
}

/*For 3 numbers we have 3! (3 factorial = 6) combinations.
Except where they're already sorted, so 5 combinations that
need to be sorted. We do these by hand, easier and simpler.*/
void	ft_sort3(int *s, int size, char c)
{
	int	min;
	int	max;

	min = ft_array_min(s, size);
	max = ft_array_max(s, size);
	if (s[0] == min && s[1] == max)
	{
		swap(s, c);
		rotate(s, size, c);
	}
	else if (s[1] == min && s[2] == max)
		swap(s, c);
	else if (s[2] == min && s[1] == max)
		revrot(s, size, c);
	else if (s[0] == max && s[1] == min)
		rotate(s, size, c);
	else if (s[0] == max && s[2] == min)
	{
		swap(s, c);
		revrot(s, size, c);
	}
}

/*For 5 elements we simply "get rid" temporarily of the
minimum and maximum values, use sort3 for the 3 remaining
and just push the edge values onto the stack once more.*/
void	ft_sort5(t_stacks *s)
{
	int	max;
	int	min;

	min = ft_array_min(s->a, s->a_size);
	max = ft_array_max(s->a, s->a_size);
	while (s->a_size != 3)
	{
		if (s->a[0] == max || s->a[0] == min)
			push_b(s);
		else
			rotate(s->a, s->a_size, 'a');
	}
	ft_sort3(s->a, s->a_size, 'a');
	push_a(s);
	if (ft_sorted(s))
	{
		push_a(s);
		rotate(s->a, s->a_size, 'a');
	}
	else
	{
		rotate(s->a, s->a_size, 'a');
		push_a(s);
	}
}

void	ft_sorter(t_stacks *s, t_mmm *m)
{
	if (s->size == 2)
		ft_sort2(s->a, 'a');
	else if (s->size == 3)
		ft_sort3(s->a, s->a_size, 'a');
	else if (s->size == 5)
		ft_sort5(s);
	else
		ft_multisort(s, m);
}
