/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:03:51 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/28 21:04:17 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printresult(char *v, int size, char max)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putchar(v[i++]);
	if (v[0] == max)
		write(1, ".\n", 2);
	else
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	v[10];
	char	max[10];
	int		i;
	int		flag;
	int		base;

	i = 0;
	while (i < n)
	{
		v[i] = i + '0';
		max[i] = (10 - n) + i + '0';
		i++;
	}
	printresult(v, n, max[0]);
	while (v[0] != max[0])
	{
		flag = n - 1;
		while (v[flag] == max[flag])
			flag--;
		base = ++v[flag];
		while (flag < n - 1)
		{
			flag++;
			v[flag] = ++base;
		}
		printresult(v, n, max[0]);
	}
}