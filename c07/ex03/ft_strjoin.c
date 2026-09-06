/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:05:14 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/29 09:45:51 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	lencheck(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_copy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

char	*empty_str(void)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		r;
	int		len;
	char	*res;

	if (size <= 0)
		return (empty_str());
	j = 0;
	len = lencheck(sep) * (size - 1);
	while (j < size)
		len += lencheck(strs[j++]);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	j = -1;
	r = 0;
	while (++j < size)
	{
		r += ft_copy(res + r, strs[j]);
		if (j < size - 1)
			r += ft_copy(res + r, sep);
	}
	res[r] = '\0';
	return (res);
}
