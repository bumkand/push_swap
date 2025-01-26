/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:33:40 by jakand            #+#    #+#             */
/*   Updated: 2025/01/23 21:05:20 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack (void)
{
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

int	push_stack (t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (-1);
	new_node->value = value;
	new_node->next = stack->top;
	new_node->prew = NULL;
	if (stack->top)
		stack->top->prew = new_node;
	else
		stack->bottom = new_node;
	stack->top = new_node;
	stack->size++;
	return (0);
}

int	pop_stack (t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		return (-1);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	if (stack->top)
		stack->top->prew = NULL;
	else
		stack->bottom = NULL;
	free (temp);
	stack->size--;
	return (value);
}

void	free_stack (t_stack *stack)
{
	while (stack->top)
		pop_stack (stack);
	free (stack);
}
