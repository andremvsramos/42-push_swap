/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:19:11 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:33:04 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

/*	On push functions, we first duplicate the OG arrays so we have somewhere
	to store them while we change the available memory for the stacks.
	Why? Because you're supposed to reduce the ammount of memory in each stack.
	There's no point in mantaining the original memory and have blank index
	spaces, therefore we increase and decrease the ammount of available memory
	'index slots' by 1 for the receiver and pusher, respectavely. */

void	push_a(t_stacks *stacks)
{
	t_stacks	*temp;
	int			i;
	int			j;

	temp = ft_calloc(1, sizeof(t_stacks));
	temp->a = ft_intcpy(stacks->a, stacks->a_size);
	temp->b = ft_intcpy(stacks->b, stacks->b_size);
	stacks->a = ft_realloc(stacks->a, (stacks->a_size + 1), sizeof(int));
	stacks->b = ft_realloc(stacks->b, (stacks->b_size - 1), sizeof(int));
	stacks->b = ft_memcpy(stacks->b, temp->b + 1,
			(sizeof(int) * (stacks->b_size - 1)));
	i = 1;
	j = 0;
	stacks->a[0] = temp->b[0];
	while (i < (stacks->a_size + 1))
		stacks->a[i++] = temp->a[j++];
	free(temp->a);
	free(temp->b);
	free(temp);
	stacks->a_size++;
	stacks->b_size--;
}

void	push_b(t_stacks *stacks)
{
	t_stacks	*temp;
	int			i;
	int			j;

	temp = ft_calloc(1, sizeof(t_stacks));
	temp->a = ft_intcpy(stacks->a, stacks->a_size);
	temp->b = ft_intcpy(stacks->b, stacks->b_size);
	stacks->a = ft_realloc(stacks->a, (stacks->a_size - 1), sizeof(int));
	stacks->b = ft_realloc(stacks->b, (stacks->b_size + 1), sizeof(int));
	stacks->a = ft_memcpy(stacks->a, temp->a + 1,
			(sizeof(int) * (stacks->a_size - 1)));
	i = 1;
	j = 0;
	stacks->b[0] = temp->a[0];
	while (i < (stacks->b_size + 1))
		stacks->b[i++] = temp->b[j++];
	free(temp->a);
	free(temp->b);
	free(temp);
	stacks->a_size--;
	stacks->b_size++;
}
