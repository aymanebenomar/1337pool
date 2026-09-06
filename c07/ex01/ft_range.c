/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:19:03 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/29 09:44:49 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	st;
	int	*arr;

	if (min >= max)
		return (NULL);
	st = max - min;
	arr = malloc((max - min) * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < st)
	{
		arr[i++] = min;
		min++;
	}
	return (arr);
}
