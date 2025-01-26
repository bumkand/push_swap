/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:48:11 by jakand            #+#    #+#             */
/*   Updated: 2025/01/23 21:03:24 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->top->value;
		a->top->value = a->top->next->value;
		a->top->next->value = temp;
	}
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size > 1)
	{
		temp = b->top->value;
		b->top->value = b->top->next->value;
		b->top->next->value = temp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int	temp;

	if (b->size > 0)
	{
		temp = pop_stack(b);
		push_stack(a, temp);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size > 0)
	{
		temp = pop_stack(a);
		push_stack(b, temp);
	}
}

void	ra(t_stack *a)
{
	t_node	*node;

	if (a->size > 1)
	{
		node = a->top;
		a->top = a->top->next;
		a->top->prew = NULL;
		node->prew = a->bottom;
		node->next = NULL;
		a->bottom->next = node;
		a->bottom = node;
	}
}

void	rb(t_stack *b)
{
	t_node	*node;

	if (b->size > 1)
	{
		node = b->top;
		b->top = b->top->next;
		b->top->prew = NULL;
		b->bottom->next = node;
		node->next = NULL;
		b->bottom = node;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*node;

	if (a->size > 1)
	{
		node = a->bottom;
		a->bottom = a->bottom->prew;
		a->bottom->next = NULL;
		node->next = a->top;
		node->prew = NULL;
		a->top = node;
	}
}

void	rrb(t_stack *b)
{
	t_node	*node;

	if (b->size > 1)
	{
		node = b->bottom;
		b->bottom = b->bottom->prew;
		b->bottom->next = NULL;
		node->next = b->top;
		node->prew = NULL;
		b->top = node;		
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
