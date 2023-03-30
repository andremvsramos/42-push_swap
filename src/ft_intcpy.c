/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:03:57 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:39:58 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/* Using the same principle of strcpy,
applying it to an integer based array.*/
int	*ft_intcpy(void *src, int size)
{
	int	*dest;

	dest = ft_calloc(size, sizeof(int));
	dest = ft_memcpy(dest, src, ((sizeof(int) * size)));
	return (dest);
}
