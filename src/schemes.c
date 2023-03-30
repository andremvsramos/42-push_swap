/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schemes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:56:13 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 17:17:33 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*See explanation for each scheme on ft_best_moves() @ moves.c*/

/*Scheme 0:
Since they need to both rotate, we will eliminate excess ra and rb
by doing rr. We find the minimum of ra and rb and use that value
as the number of rr needed. Afterwards we check which stack still
needs to be rotated and do so with the difference between the values.*/
void	ft_scheme0(t_stacks *s, t_rot *mv, int index)
{
	int	i;

	i = ft_min(mv->ra[s->b[index]], mv->rb[s->b[index]]);
	while (i--)
	{
		ft_rr(s);
		index--;
	}
	if (mv->ra[s->b[index]] > mv->rb[s->b[index]])
	{
		i = (mv->ra[s->b[index]] - mv->rb[s->b[index]]);
		while (i--)
			rotate(s->a, s->a_size, 'a');
	}
	else
	{
		i = (mv->rb[s->b[index]] - mv->ra[s->b[index]]);
		while (i--)
			rotate(s->b, s->b_size, 'b');
	}
}

/*Scheme 1:
We apply the same logic as per scheme 0.*/
void	ft_scheme1(t_stacks *s, t_rot *mv, int index)
{
	int	i;

	i = ft_min(mv->rra[s->b[index]], mv->rrb[s->b[index]]);
	while (i--)
	{
		ft_rrr(s);
		index++;
		if (index > s->b_size - 1)
			index -= s->b_size;
	}
	if (mv->rra[s->b[index]] > mv->rrb[s->b[index]])
	{
		i = mv->rra[s->b[index]] - mv->rrb[s->b[index]];
		while (i--)
			revrot(s->a, s->a_size, 'a');
	}
	else
	{
		i = mv->rrb[s->b[index]] - mv->rra[s->b[index]];
		while (i--)
			revrot(s->b, s->b_size, 'b');
	}
}

/*Scheme 2:
Using i as the number of ra and rrb we simply loop the functions
while decrementing i by 1 each time.*/
void	ft_scheme2(t_stacks *s, t_rot *mv, int index)
{
	int	i;

	i = mv->ra[s->b[index]];
	while (i > 0)
	{
		rotate(s->a, s->a_size, 'a');
		i--;
	}
	i = mv->rrb[s->b[index]];
	while (i > 0)
	{
		revrot(s->b, s->b_size, 'b');
		i--;
	}
}

/*Scheme 3:
Same concept as scheme 2.*/
void	ft_scheme3(t_stacks *s, t_rot *mv, int index)
{
	int	i;

	i = mv->rra[s->b[index]];
	while (i > 0)
	{
		revrot(s->a, s->a_size, 'a');
		i--;
	}
	i = mv->rb[s->b[index]];
	while (i > 0)
	{
		rotate(s->b, s->b_size, 'b');
		i--;
	}
}
