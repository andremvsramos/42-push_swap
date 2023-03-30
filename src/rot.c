/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:56:30 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 17:10:06 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

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
 * @param c
 This will be the flag that tells the program what move will it
 print.
 'a' -> ra | rra
 'b' -> rb | rrb
 'c' -> rr | rrr
 */
void	rotate(int *stack, int size, char c)
{
	int	first;
	int	i;

	if (c != 'c')
		ft_printf("r%c\n", c);
	i = 0;
	first = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = first;
}

void	revrot(int *stack, int size, char c)
{
	int	last;
	int	i;

	i = size - 1;
	last = stack[i];
	if (c != 'c')
		ft_printf("rr%c\n", c);
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
}

void	ft_rr(t_stacks *s)
{
	rotate(s->a, s->a_size, 'c');
	rotate(s->b, s->b_size, 'c');
	ft_printf("rr\n");
}

void	ft_rrr(t_stacks *s)
{
	revrot(s->a, s->a_size, 'c');
	revrot(s->b, s->b_size, 'c');
	ft_printf("rrr\n");
}
