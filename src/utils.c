/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:58 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 17:22:19 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*Google*/
void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/*Finding the minimum, median and maximum values
of the stack.*/
void	ft_median(t_stacks *s, t_mmm *m)
{
	int	i;

	m->min = s->a[0];
	m->max = m->min;
	m->med = s->size / 2;
	i = 0;
	while (i < s->size)
	{
		if (s->a[i] < m->min)
			m->min = s->a[i];
		else if (s->a[i] > m->max)
			m->max = s->a[i];
		i++;
	}
}

/*Checking if all inputs are digits.
Words are a no-no.*/
int	ft_strdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
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

/*Checking if all the inputs are within integer range.*/
int	ft_check_num(int ac, char **av, int n)
{
	int	i;

	if (n == 1)
		i = 1;
	else
		i = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN
			|| !ft_strdigit(av[i]))
		{
			write(2, "Error\n", ft_strlen("Error\n"));
			return (-1);
		}
		i++;
	}
	return (ft_check_doubles(ac, av, n));
}
