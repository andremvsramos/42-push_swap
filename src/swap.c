/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:18:27 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 17:22:07 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*If you're looking for an explanation on this,
please refer to google*/
void	swap(int *stack, char c)
{
	int	aux;

	if (c != 'c')
		ft_printf("s%c\n", c);
	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void	ft_ss(t_stacks *stacks)
{
	swap(stacks->a, 'c');
	swap(stacks->b, 'c');
	ft_printf("ss\n");
}
