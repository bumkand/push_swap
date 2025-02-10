/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaandras <jaandras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:26:35 by jakand            #+#    #+#             */
/*   Updated: 2025/02/09 17:36:51 by jaandras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_move(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		pb(a, b);
		write(1, "pb\n", 3);
		return ;
	}
	if (a->size > 4)
	{
		pb(a, b);
		pb(a, b);
		write(1, "pb\n", 3);
		write(1, "pb\n", 3);
	}
}

void	move_best_to_b(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*best_node;
	int		min_operations;
	int		operations;

	current_a = a->top;
	best_node = NULL;
	min_operations = 2147483646;
	// printf("a->size:%d\n", a->size);
	while (current_a != NULL)
	{
		// printf("%d\n", current_a->value);
		operations = calculate_operations(a, b, current_a->value);
		// printf("opp: %d\n", operations);
		if (operations < min_operations)
		{
			min_operations = operations;
			best_node = current_a;
		}
		current_a = current_a->next;
		// printf("min_operations: %d\n", min_operations);
	}
	execute_moves(a, b, best_node->value);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max_value;
	int		position;
	int		max_position;

	current = stack->top;
	max_value = -2147483648;
	position = 0;
	max_position = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_position = position;
		}
		current = current->next;
		position++;
	}
	return (max_position);
}

void	biggest_to_top(t_stack *stack)
{
	int		max_position;

	max_position = find_max(stack);
	if (max_position <= (stack->size / 2))
	{
		while (max_position > 0)
		{
			rb(stack);
			max_position--;
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (max_position < stack->size)
		{
			rrb(stack);
			max_position++;
			write(1, "rrb\n", 4);
		}
	}
}

// void	biggest_to_top(t_stack *stack)
// {
// 	t_node	*current;
// 	int		max_value;
// 	int		position;
// 	int		max_position;

// 	current = stack->top;
// 	max_value = -2147483648;
// 	position = 0;
// 	max_position = 0;
// 	while (current)
// 	{
// 		if (current->value > max_value)
// 		{
// 			max_value = current->value;
// 			max_position = position;
// 		}
// 		current = current->next;
// 		position++;
// 	}
// 	// Presunieme maximum na vrch pomocou `rb` alebo `rrb`
// 	if (max_position <= (stack->size / 2))
// 	{
// 		while (max_position > 0)
// 		{
// 			rb(stack);
// 			max_position--;
// 			write(1, "rb\n", 3);
// 		}
// 	}
// 	else
// 	{
// 		while (max_position < stack->size)
// 		{
// 			rrb(stack);
// 			max_position++;
// 			write(1, "rrb\n", 4);
// 		}
// 	}
// }

// int	is_sorted_a(t_stack *a)
// {
// 	int	i;

// 	i = 0;
// 	while (a->data[i] > a->data[i + 1])
// 	{
// 		if (a->data[i] < a->data[i + 1])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int     is_sorted_b(t_stack *b)
// {
// 	int     i;

// 	i = 0;
// 	while (b->data[i] < b->data[i + 1])
// 	{
// 		if (b->data[i] > b->data[i + 1])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
