/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 11:02:59 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/22 15:47:01 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	fill_digit(long n, char *base, char *s, int lenbase)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		s[i++] = base[n % lenbase];
		n /= lenbase;
	}
	return (i);
}

void	put_reverse(char *s, int i)
{
	while (i > 0)
		write(1, &s[--i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		lenbase;
	char	s[32];
	long	n;

	n = nbr;
	lenbase = checkbase(base);
	if (!lenbase)
		return ;
	if (n == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = fill_digit(n, base, s, lenbase);
	put_reverse(s, i);
}
