/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:03:28 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:14:36 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

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

/*Checking if any number is greater than the next.
If it is, returns 0, as in, the stack isn't sorted.
Returns 1 if no number is greater than the next.*/
int	ft_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->a_size == 1)
		exit (1);
	while (i < s->a_size - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
