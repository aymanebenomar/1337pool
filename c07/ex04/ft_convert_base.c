/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 21:10:53 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/29 09:46:53 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int nbr, char *base_to);

int	ft_is_valid_base(char *base_from)
{
	int	i;
	int	j;

	if (base_from[0] == '\0' || base_from[1] == '\0')
		return (0);
	i = 0;
	while (base_from[i])
	{
		if (base_from[i] == '-' || base_from[i] == '+'
			|| (base_from[i] >= 9 && base_from[i] <= 13)
			|| base_from[i] == ' ')
			return (0);
		j = i + 1;
		while (base_from[j])
		{
			if (base_from[i] == base_from[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	ft_indexof_base(char c, char *base_from)
{
	int	i;

	i = 0;
	while (base_from[i])
	{
		if (base_from[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base_from)
{
	int	i;
	int	s;
	int	r;
	int	len;

	if (!ft_is_valid_base(base_from))
		return (0);
	len = ft_base_len(base_from);
	r = 0;
	i = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_indexof_base(str[i], base_from) != -1)
	{
		r = r * len + ft_indexof_base(str[i], base_from);
		i++;
	}
	return (r * s);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	res;

	if (!ft_is_valid_base(base_from)
		|| !ft_is_valid_base(base_to))
		return (NULL);
	res = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(res, base_to));
}
