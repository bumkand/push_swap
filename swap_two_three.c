/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:18:54 by jakand            #+#    #+#             */
/*   Updated: 2025/02/11 16:30:43 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_num(t_stack *a)
{
	t_node		*top;
	t_node		*bottom;

	top = a->top;
	bottom = a->bottom;

	if (top->value > bottom->value && a->size == 2)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
}

void    swap_rev_rot(t_stack *a, t_node *top, t_node *bottom, t_node *mid)
{
    if (top->value > mid->value && mid->value > bottom->value)
	{
		sa(a);
        write(1, "sa\n", 3);
		rra(a);
        write(1, "rra\n", 4);
	}
	else if (top->value < mid->value && mid->value > bottom->value
            && top->value < bottom->value)
	{
		rra(a);
        write(1, "rra\n", 4);
		sa(a);
        write(1, "sa\n", 3);
	}
}

void	three_num(t_stack *a)
{
	t_node		*top;
	t_node		*bottom;
	t_node		*mid;

	top = a->top;
	bottom = a->bottom;
	mid = a->top->next;
	if (a->size > 3)
		return ;
	if (top->value > mid->value && top->value < bottom->value)
	{
		sa(a);
        write(1, "sa\n", 3);
	}
	else if (top->value > mid->value && mid->value < bottom->value)
	{
		ra(a);
        write(1, "ra\n", 3);
	}
	else if (top->value < mid->value && top->value > bottom->value)
	{
		rra(a);
        write(1, "rra\n", 4);
	}
	swap_rev_rot(a, top, bottom, mid);
}

