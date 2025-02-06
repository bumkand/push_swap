/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:41:20 by jakand            #+#    #+#             */
/*   Updated: 2025/02/06 18:15:36 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static size_t	ft_str_len(char const *s, char c)
{
	size_t	str_len;

	if (!ft_strchr(s, c))
		str_len = ft_strlen(s);
	else
		str_len = ft_strchr(s, c) - s;
	return (str_len);
}

static void	ft_free(int i, char **lptr)
{
	while (i > 0)
		free(lptr[--i]);
	free(lptr);
}

static char	**ft_process_string(char const *s, char c, char **lptr)
{
	int		i;
	size_t	str_len;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			str_len = ft_str_len(s, c);
			lptr[i] = ft_substr(s, 0, str_len);
			if (!lptr[i])
			{
				ft_free(i, lptr);
				return (NULL);
			}
			i++;
			s += str_len;
		}
	}
	lptr[i] = NULL;
	return (lptr);
}

char	**ft_split(char const *s, char c)
{
	char	**lptr;

	lptr = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !lptr)
		return (NULL);
	return (ft_process_string(s, c, lptr));
}
