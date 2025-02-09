/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:42:14 by jaandras          #+#    #+#             */
/*   Updated: 2025/02/08 16:50:43 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*node;

	if (a->size > 1)
	{
		node = a->top;
		a->top = node->next;
		a->top->prew = NULL;
		node->prew = a->bottom;
		a->bottom->next = node;
		a->bottom = node;
		node->next = NULL;
	}
	a->operations++;
}

void	rb(t_stack *b)
{
	t_node	*node;

	if (b->size > 1)
	{
		node = b->top;
		b->top = node->next;
		b->top->prew = NULL;
		node->prew = b->bottom;
		b->bottom->next = node;
		b->bottom = node;
		node->next = NULL;
	}
	b->operations++;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	a->operations--;
}
