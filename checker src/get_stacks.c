/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:16:59 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:13:42 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	ft_error(char *av)
{
	if (!*av)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit (1);
	}
}

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

/*Pretty self-explanatory.*/
int	ft_check_doubles(int ac, char **av, int n)
{
	int	i;
	int	j;

	if (n == 1)
		i = 1;
	else
		i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				write(2, "Error\n", ft_strlen("Error\n"));
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*For arguments without quotation marks, therefore multiple inputs.*/
void	ft_multiarg_stack(int ac, char **av, t_stacks *s)
{
	int	i;

	i = 0;
	if (ft_check_num(ac, av, 1) == -1)
		exit (1);
	ft_stacks_init(s, ac);
	while (av[i + 1])
	{
		s->a[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

/*For a single argument, using quotation marks.*/
void	ft_get_stack(char *av, t_stacks *s)
{
	char	**stack;
	int		i;

	i = 0;
	ft_error(av);
	stack = ft_split(av, ' ');
	if (ft_check_num(ft_wordcount(av, ' '), stack, 0) == -1)
	{
		ft_free_split(stack);
		exit (1);
	}
	s->size = ft_wordcount(av, ' ');
	s->a_size = s->size;
	s->a = ft_calloc(s->a_size, sizeof(int));
	s->b = ft_calloc(0, sizeof(int));
	s->b_size = 0;
	while (stack[i])
	{
		s->a[i] = ft_atoi(stack[i]);
		i++;
	}
	ft_free_split(stack);
}
