/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:22:20 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 17:07:52 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*Here we will find what index we will be working with.
So we need to find the first ocurrence where the least
ammount of moves (moves->least) is less than the current
move ammount (INT_MAX). Once we find it, we return its position
on the B stack, so we can work with it.*/
int	ft_elem_to_move(t_stacks *s, t_rot *moves)
{
	int	i;
	int	index;
	int	ammount;

	ammount = INT_MAX;
	index = -1;
	i = 0;
	while (i < s->b_size)
	{
		if (moves->least[s->b[i]] < ammount)
		{
			ammount = moves->least[s->b[i]];
			index = i;
		}
		i++;
	}
	return (index);
}

/*Here we define the schemes that we will be using bm array.
Each index will point to a different scheme:
0 -> Both of the stacks rotate
1 -> Both of the stacks reverse rotate
2 -> A Rotates and B reverse rotates
3 -> A Reverse rotates and B rotates

bm[0] -> we need to find how many times they will rotate
bm[1] ->  "                  "               "    reverse rotate
bm[2] -> the ammount of rotations (A) and reverse rotations (B)
bm[3] -> the ammount of rotations (B) and reverse rotations (A)

Afterwards we check which index of bm has the lowest value for
each value of B.
That means we will find the minimum number of moves for B, that will
be bm[j] and the scheme we will use for that B value (j).*/
void	ft_best_moves(t_stacks *s, t_rot *moves)
{
	int	bm[4];
	int	i;
	int	j;

	i = 0;
	while (i < s->b_size)
	{
		j = 0;
		bm[0] = ft_max(moves->ra[s->b[i]], moves->rb[s->b[i]]);
		bm[1] = ft_max(moves->rra[s->b[i]], moves->rrb[s->b[i]]);
		bm[2] = moves->ra[s->b[i]] + moves->rrb[s->b[i]];
		bm[3] = moves->rra[s->b[i]] + moves->rb[s->b[i]];
		while (j < 4)
		{
			if (bm[j] < moves->least[s->b[i]])
			{
				moves->least[s->b[i]] = bm[j];
				moves->scheme[s->b[i]] = j;
			}
			j++;
		}
		i++;
	}
}

/*Here we decide what scheme we will be using for each move*/
void	ft_move(t_stacks *s, t_rot *mv)
{
	int	index;

	index = ft_elem_to_move(s, mv);
	if (index == -1)
		return ;
	if (mv->scheme[s->b[index]] == 0)
		ft_scheme0(s, mv, index);
	else if (mv->scheme[s->b[index]] == 1)
		ft_scheme1(s, mv, index);
	else if (mv->scheme[s->b[index]] == 2)
		ft_scheme2(s, mv, index);
	else if (mv->scheme[s->b[index]] == 3)
		ft_scheme3(s, mv, index);
	push_a(s);
}
