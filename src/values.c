/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:13:50 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 12:33:09 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_array_max(int *s, int size)
{
	int	i;
	int	max;

	i = 0;
	max = s[0];
	while (i < size)
	{
		if (max < s[i])
			max = s[i];
		i++;
	}
	return (max);
}

int	ft_array_min(int *s, int size)
{
	int	i;
	int	min;

	i = 1;
	min = s[0];
	while (i < size)
	{
		if (min > s[i])
			min = s[i];
		i++;
	}
	return (min);
}
