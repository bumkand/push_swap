/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:24 by jakand            #+#    #+#             */
/*   Updated: 2025/02/08 16:54:56 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(s);
	j = 0;
	ptr = (char *) malloc((i + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_char;
	char	*ptr;

	ptr = NULL;
	i = 0;
	c_char = c;
	while (s[i])
	{
		if (s[i] == c_char)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c_char)
		return ((char *) &s[i]);
	return (ptr);
}
