/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:30:15 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:08:26 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	ft_stacks_init(t_stacks *stacks, int ac)
{
	stacks->size = ac - 1;
	stacks->a = ft_calloc(stacks->size, sizeof(int));
	stacks->b = ft_calloc(0, sizeof(int));
	stacks->a_size = stacks->size;
	stacks->b_size = 0;
}

/*Checking whether the input is recognized
as one of the available commands. If not,
'Error' will be printed.*/
static void	ft_mover(char *move, t_stacks *s)
{
	if (!ft_strncmp(move, "sa\n", 3))
		swap(s->a);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap(s->b);
	else if (!ft_strncmp(move, "ss\n", 3))
		ft_ss(s);
	else if (!ft_strncmp(move, "ra\n", 3))
		rotate(s->a, s->a_size);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate(s->b, s->b_size);
	else if (!ft_strncmp(move, "rr\n", 3))
		ft_rr(s);
	else if (!ft_strncmp(move, "rra\n", 4))
		revrot(s->a, s->a_size);
	else if (!ft_strncmp(move, "rrb\n", 4))
		revrot(s->b, s->b_size);
	else if (!ft_strncmp(move, "rrr\n", 4))
		ft_rrr(s);
	else if (!ft_strncmp(move, "pa\n", 3))
		push_a(s);
	else if (!ft_strncmp(move, "pb\n", 3))
		push_b(s);
	else
		write(2, "Error\n", 6);
}

/* Reading the console input by utilizing 0 as
the file descriptor. The program stops reading
inputs when you input 'done'.*/
static void	ft_do_moves(t_stacks *s)
{
	char	*move;

	move = ft_strdup("");
	while (move)
	{
		if (move[0])
			ft_mover(move, s);
		if (!ft_strncmp(move, "done\n", 5))
			break ;
		free(move);
		move = get_next_line(0);
	}
	free(move);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	if (ac == 2)
		ft_get_stack(av[1], &stacks);
	else
		ft_multiarg_stack(ac, av, &stacks);
	ft_do_moves(&stacks);
	if (!ft_sorted(&stacks) || stacks.b_size)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(stacks.a);
	free(stacks.b);
	return (0);
}
