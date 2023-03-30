/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:06:38 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 16:54:35 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*Here we copy the original stack input and use bubble
sort method to sort the temporary array, so we can acurately
index the original values using their original position in
the original stack.
(See example below)*/
static void	ft_indexer(t_stacks *s, int *temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a_size)
	{
		j = 0;
		while (j < s->a_size)
		{
			if (s->a[i] == temp[j])
			{
				s->a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_and_convert_index(t_stacks *s)
{
	int	i;
	int	j;
	int	*temp;

	temp = ft_calloc(s->size, sizeof(int));
	temp = ft_memcpy(temp, s->a, (sizeof(int) * s->a_size));
	i = 0;
	while (i < s->a_size)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (temp[i] > temp[j])
				ft_swap(&temp[i], &temp[j]);
			j++;
		}
		i++;
	}
	ft_indexer(s, temp);
	free(temp);
}
/*

For example:
Original : 50 , 9 , 2 , -1
Temporary: -1 , 2 , 9 , 50

			||
			\/

Indexed  :  3 , 2 , 1 , 0*/

/*Here we're going to find where each number must
be when returning to the original stack (push_a function).
To that end, we're subtracting every element from stack a
(identified by s->a[i]) with the value of the current stack B
input (identified by s->b[index]). If the difference is positive
and less than the current minimum value, that means the number
goes before that stack A element. We repeat this process to check
if there's an even smaller difference or if we can move on to the next
value in stack B (ft_indexing function).
When we find the position of the element from stack A that needs to be
on top so we can transfer the current element from B, we save it as the
number of rotations and reverse rotations needed to put that number upfront.

For example:
Stack A: 0 , 5 , 3
Stack B: 1 , 2 , 4
(Here the stacks have been through the process of
indexation and pushing non-anchor values from A to B)

Be index = 0 -> Cycling through A with B[0] (= 1)

0 - 1 = -1
5 - 1 =  4
3 - 1 =  2 <--- This will be the lowest value
Therefore we save the position of 3, which is a[2].
That also means that for a[2] to be on top, we need to rotate the
stack 2 times.
The reverse will be the difference between the sum of the total ammount
of elements in the stack and the position of a[2] (3 - 2 = 1);

Result:
RA[S->B[INDEX]] <=> RA[S->B[0]] <=> RA[1] = 2
RRA[S-B[INDEX]] <=> RRA[S->B[0]] <=> RRA[1] = 1

Below we can also ascertain that the number of moves for b[0]
to be on top of the stack will be:
RB[S->B[INDEX]] <=> RB[S->B[0]] <=> RB[1] = 0
RRB[S-B[INDEX]] <=> RRB[S->B[0]] <=> RRB[1] = 3
*/
void	ft_a_indexing(t_stacks *s, int index, t_rot *moves)
{
	int	min;
	int	pos;
	int	i;
	int	diff;

	i = 0;
	pos = 0;
	min = INT_MAX;
	diff = 0;
	while (i < s->a_size)
	{
		diff = s->a[i] - s->b[index];
		if (diff > 0 && diff < min)
		{
			pos = i;
			min = diff;
		}
		i++;
	}
	moves->ra[s->b[index]] = pos;
	moves->rra[s->b[index]] = s->a_size - pos;
}

/*Here we turn the least moves array of the moves
structure to INT_MAX, this gives us a form of comparison
to other values, since we're trying to get the least ammount.
*/
void	ft_indexing(t_stacks *s, t_rot *moves)
{
	int	i;

	i = 0;
	while (i < s->size)
		moves->least[i++] = INT_MAX;
	i = 0;
	while (i < s->b_size)
	{
		ft_a_indexing(s, i, moves);
		moves->rb[s->b[i]] = i;
		moves->rrb[s->b[i]] = s->b_size - i;
		i++;
	}
}

/*NOTE:
MOVES STRUCTURE ARRAYS WILL HAVE ALWAYS THE ORIGINAL AMMOUNT
OF INPUTS (S->SIZE or S->A_SIZE + S->B_SIZE)

This allows us to refer to the ammount of moves the value,
not the position, will need.*/
