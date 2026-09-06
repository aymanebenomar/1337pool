/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:16:24 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/15 08:46:24 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		k = 0;
		while (k < size - 1)
		{
			if (tab[k] > tab[k + 1])
			{
				temp = tab[k + 1];
				tab[k + 1] = tab[k];
				tab[k] = temp;
			}
			k++;
		}
		i++;
	}
}
