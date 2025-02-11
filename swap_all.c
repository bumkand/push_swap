/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:48:31 by jakand            #+#    #+#             */
/*   Updated: 2025/02/11 22:05:29 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_num(t_stack *a, t_stack *b)
{
    if (a->size > 2)
	{
		first_move(a, b);
		// write_stack(a, b);
		while (a->size != 0) // Spustenie funkcie x krat
		{
			move_best_to_b(a, b);
			// write_stack(a, b);
		}
		biggest_to_top(b);
		// write_stack(a, b);
		while (b->size != 0)
		{
			pa(a, b);
			write(1, "pa\n", 3);
			// write_stack(a, b);
		}
	}
}
