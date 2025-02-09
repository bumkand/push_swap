/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:42:43 by jaandras          #+#    #+#             */
/*   Updated: 2025/02/08 16:50:50 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*node;

	if (a->size > 1)
	{
		node = a->bottom;
		if (!a->bottom->prew)
			return ;
		a->bottom = node->prew;
		a->bottom->next = NULL;
		node->next = a->top;
		node->prew = NULL;
		if (a->top)
			a->top->prew = node;
		a->top = node;
	}
	a->operations++;
}

void	rrb(t_stack *b)
{
	t_node	*node;

	if (b->size > 1)
	{
		node = b->bottom;
		if (!b->bottom->prew)
		{
			return ;
		}
		b->bottom = node->prew;
		b->bottom->next = NULL;
		node->next = b->top;
		node->prew = NULL;
		if (b->top)
			b->top->prew = node;
		b->top = node;
	}
	b->operations++;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	a->operations--;
}
