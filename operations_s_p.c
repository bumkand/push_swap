/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:48:11 by jakand            #+#    #+#             */
/*   Updated: 2025/02/08 16:42:40 by jaandras         ###   ########.fr       */
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
