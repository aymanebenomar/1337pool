/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:35:21 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/29 09:45:36 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	rng;
	int	i;
	int	*res;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	rng = max - min;
	i = 0;
	res = malloc(rng * sizeof(int));
	if (!res)
		return (-1);
	while (i < rng)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (max - min);
}
