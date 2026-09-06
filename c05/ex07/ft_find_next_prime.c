/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 10:49:01 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/23 11:00:09 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	isprime(int n)
{
	int	i;

	i = 2;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!isprime(nb))
		nb++;
	return (nb);
}
