/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:34:29 by abenomar          #+#    #+#             */
/*   Updated: 2026/08/23 15:37:35 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = argc - 1;
	while (j >= 1)
	{
		i = 0;
		while (argv[j][i])
			write(1, &argv[j][i++], 1);
		write(1, "\n", 1);
		j--;
	}
	return (0);
}
