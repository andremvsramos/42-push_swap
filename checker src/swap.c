/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:18:27 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:34:11 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

/**
 * @brief It's a swap, if you don't know how it works,
 than why're you trying to understand this project?
 */
void	swap(int *stack)
{
	int	aux;

	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void	ft_ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
}
