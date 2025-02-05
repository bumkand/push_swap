/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:48:11 by jakand            #+#    #+#             */
/*   Updated: 2025/02/05 21:04:35 by jakand           ###   ########.fr       */
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
	a->operations++;
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
	b->operations++;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	a->operations--;
}

void	pa(t_stack *a, t_stack *b)
{
	int	temp;

	if (b->size > 0)
	{
		temp = pop_stack(b);
		push_stack(a, temp);
	}
	a->operations++;
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size > 0)
	{
		temp = pop_stack(a);
		push_stack(b, temp);
	}
	a->operations++;
}

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
