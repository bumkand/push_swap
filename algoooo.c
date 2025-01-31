/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoooo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:26:35 by jakand            #+#    #+#             */
/*   Updated: 2025/01/30 19:35:51 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_move(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		pb(a, b);
		return ;
	}
	if (a->size > 4)
	{
		pb(a, b);
		pb(a, b);
	}
}

int	get_best_position_b(t_stack *a, t_stack *b, int value) // myslim si ze tu su zle podmienky
{
	t_node	*current_b;
	t_node	*current_a;
	int	position;

	int	nearest_value;
	int	i;
	int	best_position;
	
	position = 0;
	current_b = b->top;
	current_a = a->top;
	nearest_value = 2147483647;
	i = 0;
	while (current_a && current_a->value != value)
	{
		current_a = current_a->next;
	}
	if (!current_a)
		return (-1);
	while (current_b)
	{
		if (current_a->value > current_b->value)
		{
			i = current_a->value - current_b->value;
			if (i < nearest_value)
			{
				nearest_value = i;
				best_position = position;
			}
		}
		if (current_a->value < current_b->value)
		{
			i = current_b->value - current_a->value;
			if (i < nearest_value)
			{
				nearest_value = i;
				best_position = position + 1;
			}
		}
		current_b = current_b->next;
		position++;
	}
	return (best_position);
}

int	calculate_operations(t_stack *a, t_stack *b, int value)
{
	t_node	*current;
	int	pos_a;
	int	pos_b;
	int	operations;

	pos_a = 0;
	current = a->top;
	operations = -1;
	while (current && current->value != value)
	{
		current = current->next;
		pos_a++;
	}
	if (current)
		return (-1);
	pos_b = get_best_position_b(a, b, value);
	if (pos_a <= (a->size / 2) && pos_b <= (b->size / 2))
		operations = (pos_a > pos_b) ? pos_a : pos_b; // Operation rr
	if (pos_a > (a->size / 2) && pos_b > (b->size / 2))
	{
		if (a->size - pos_a > b->size - pos_b)
			operations = a->size - pos_a;
		else
			operations = b->size - pos_b;
	} // Operations rrr
	if (pos_a <= (a->size / 2) && pos_b > (b->size / 2))
		operations = pos_a + (b->size - pos_b);		//ra + rrb
	if (pos_a > (a->size / 2) && pos_b <= (a->size / 2))
		operations = (a->size - pos_a) + pos_b; // Operations rra + rb
	if (operations == -1)
		return (0);
	return (operations);
}


void	execute_moves(t_stack *a, t_stack *b, int value)
{
	t_node	*current;
	int	pos_a;
	int	pos_b;

	current = a->top;
	pos_a = 0;
	while (current->value != value)
	{
		current = current->next;
		pos_a++;
	}
	pos_b = get_best_position_b(a, b, current->value);
	if (pos_b == -1)
		return ;
	if (pos_a <= (a->size / 2) && pos_b <= (b->size / 2))
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b);
			pos_a--;
			pos_b--;
		}
		while (pos_a-- > 0)
			ra(a);
		while (pos_b-- > 0)
			rb(b);
	}
	else if (pos_a > (a->size / 2) && pos_b > (b->size / 2))
	{
		while ((a->size - pos_a) > 0 && (b->size - pos_b) > 0)
		{
			rrr(a, b);
			pos_a--;
			pos_b--;
		}
		while (pos_a++ < a->size)
			rra(a);
		while (pos_b++ < b->size - 1)
			rrb(b);
	}
	else if (pos_a <= (a->size / 2))
	{
		while (pos_a-- > 0)
			ra(a);
	}
	else if (pos_a > (a->size / 2))
	{
		while (pos_a++ < a->size)
			rra(a);
	}
	if (pos_b <= (b->size / 2))
	{
		while (pos_b-- > 0)
			rb(b);
	}
	else if (pos_b > (b->size / 2))
	{
		while (pos_b++ < b->size - 1)
			rrb(b);
	}
	pb(a, b);
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
	while (current_a != NULL)
	{
		operations = calculate_operations(a, b, current_a->value);
		if (operations < min_operations)
		{
			min_operations = operations;
			best_node = current_a;
		}
		current_a = current_a->next;
	}
	if (!best_node)
		return ;
	execute_moves(a, b, best_node->value);
}


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
