/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:38:30 by andvieir          #+#    #+#             */
/*   Updated: 2023/03/30 15:48:17 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ps.h"

/*Homemade realloc. Pretty useful huh?*/
void	*ft_realloc(void *data, size_t nmemb, size_t size)
{
	free(data);
	data = ft_calloc(nmemb, size);
	return (data);
}
