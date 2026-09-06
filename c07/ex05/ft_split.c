/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 15:39:55 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/29 10:15:48 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	countwords(char *s, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], charset))
			i++;
		if (s[i] && !is_sep(s[i], charset))
		{
			count++;
			while (s[i] && !is_sep(s[i], charset))
				i++;
		}
	}
	return (count);
}

int	ft_alloc_words(char *str, char *charset, char **res)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		j = 0;
		while (str[i + j] && !is_sep(str[i + j], charset))
			j++;
		if (j > 0)
		{
			res[w] = malloc((j + 1) * sizeof(char));
			if (!res[w])
				return (0);
			w++;
			i += j;
		}
	}
	return (1);
}

void	ft_fill_words(char *str, char *charset, char **res)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		j = 0;
		while (str[i] && !is_sep(str[i], charset))
		{
			res[w][j] = str[i];
			i++;
			j++;
		}
		if (j > 0)
			res[w][j++] = '\0';
		w += (j > 0);
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		nw;

	nw = countwords(str, charset);
	res = malloc((nw + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!ft_alloc_words(str, charset, res))
		return (NULL);
	ft_fill_words(str, charset, res);
	res[nw] = NULL;
	return (res);
}
