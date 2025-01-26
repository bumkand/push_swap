/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:11:07 by jakand            #+#    #+#             */
/*   Updated: 2025/01/20 22:18:56 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	long int		store;
	int				sign;

	i = 0;
	store = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || \
			*nptr == '\r' || *nptr == '\f' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while ((unsigned char)nptr[i] >= '0' && (unsigned char)nptr[i] <= '9')
	{
		store = store * 10 + ((unsigned char)nptr[i] - 48);
		i++;
	}
	return (store * sign);
}

// int	main(void)
// {
// 	printf("%d\n", (ft_atoi("+--54")));
// 	return (0);
// }
