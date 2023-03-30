/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:18:36 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:59:14 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

static void	ft_rot_init(t_rot *moves, t_stacks *s)
{
	int	i;

	i = 0;
	moves->ra = ft_calloc(s->size, sizeof(int));
	moves->rra = ft_calloc(s->size, sizeof(int));
	moves->rb = ft_calloc(s->size, sizeof(int));
	moves->rrb = ft_calloc(s->size, sizeof(int));
	moves->least = ft_calloc(s->size, sizeof(int));
	moves->scheme = ft_calloc(s->size, sizeof(int));
}

/*Remember to always free whatever memory
you've allocated!*/
static void	ft_moves_free(t_rot *moves)
{
	free(moves->ra);
	free(moves->rra);
	free(moves->rb);
	free(moves->rrb);
	free(moves->least);
	free(moves->scheme);
}

/*This sorter is called whenever the number
of inputs is different than 2, 3 and 5.
Here we initialize the moves structure, which will
hold the ammount of moves each input requires to
be correctly sorted.
When researching sorting methods, I've found that
most, if not all, use indexes to figure out what numbers
we are sorting in a different stack and which numbers
we are using as anchors (in this case, we are using the
minimum, median and maximum numbers as anchors and pushing
every other input to the B stack).
Also converting all inputs to a indexing serial,
starting from 0 to n, allows us to freely compare each
input with eachother in intervals of 1.

For example:
10, 25472, -9569
		||
		\/
  1,    2,    0

The converted numbers seem much more reasonable, do they not?
*/
void	ft_multisort(t_stacks *s, t_mmm *m)
{
	t_rot	*moves;

	ft_get_and_convert_index(s);
	moves = ft_calloc(1, sizeof(t_rot));
	ft_median(s, m);
	ft_rot_init(moves, s);
	while (s->a_size != 3)
	{
		if (s->a[0] == m->min || s->a[0] == m->max
			|| s->a[0] == m->med)
			rotate(s->a, s->a_size, 'a');
		else
			push_b(s);
	}
	ft_sort3(s->a, s->a_size, 'a');
	while (s->b_size)
	{
		ft_indexing(s, moves);
		ft_best_moves(s, moves);
		ft_move(s, moves);
	}
	free(m);
	ft_moves_free(moves);
	free(moves);
}
