/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:05:47 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:39:23 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*Checking if any number is greater than the next.
If it is, returns 0, as in, the stack isn't sorted.
Returns 1 if no number is greater than the next.*/
int	ft_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->a_size == 1)
		exit (1);
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*Here is where we rotate the stack so
it is ordered from lowest to highest.
We do so by checking where the index 0 is
on the stack.
After knowing its position we check whether
it is in the first or latter half of the stack.
We do a normal rotate if its in the first and
a reverse rotate if its in the latter.
This allows us to rotate the entire stack via
the shortest path.*/
void	ft_rot_sort(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a_size)
	{
		if (s->a[i] == 0)
			break ;
		i++;
	}
	if (i < s->a_size / 2)
	{
		while (!ft_sorted(s))
			rotate(s->a, s->a_size, 'a');
	}
	else
	{
		while (!ft_sorted(s))
			revrot(s->a, s->a_size, 'a');
	}
}
