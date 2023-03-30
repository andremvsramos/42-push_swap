/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:56:30 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:34:01 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

/**
 * @brief
 * The rotate and reverse rotate functions were programmed
 	to be able to be used dynamically. This means not using the
	stack structure, but instead inputing what stack we're changing.
 * @param stack
 The stack that we are changing. When we call the
 function we input either stack->a or stack->b.
 * @param size
 The size of the stack we're changing,
 so we have a way to know the current size.
 */

void	rotate(int *stack, int size)
{
	int	first;
	int	i;

	i = 0;
	first = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = first;
}

void	revrot(int *stack, int size)
{
	int	last;
	int	i;

	i = size - 1;
	last = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	ft_rr(t_stacks *s)
{
	rotate(s->a, s->a_size);
	rotate(s->b, s->b_size);
}

void	ft_rrr(t_stacks *s)
{
	revrot(s->a, s->a_size);
	revrot(s->b, s->b_size);
}
