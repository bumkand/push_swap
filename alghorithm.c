/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:26:35 by jakand            #+#    #+#             */
/*   Updated: 2025/02/05 20:59:00 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_move(t_stack *a, t_stack *b)
{
	if (a->size > 4)
	{
		pb(a, b);
		pb(a, b);
		write(1, "pb\n", 3);
		write(1, "pb\n", 3);
	}
	if (a->size == 4)
	{
		pb(a, b);
		write(1, "pb\n", 3);
		return ;
	}
}

int	get_best_position_b(t_stack *b, int value) // myslim si ze tu su zle podmienky
{
	t_node	*current_b;
	int	best_position;
	int	position;
	int	min_diff;
	int	max_value;
	int	min_value;
	int	max_position;
	int	min_position;

	current_b = b->top;
	best_position = 0;
	position = 0;
	min_diff = 2147483647;
	max_value = -2147483648;
	min_value = 2147483647;
	max_position = 0;
	min_position = 0;
	while (current_b)
    {
        if (current_b->value > max_value)
        {
            max_value = current_b->value;
            max_position = position;
        }
        if (current_b->value < min_value)
        {
            min_value = current_b->value;
            min_position = position;
        }

        if (current_b->value > value && current_b->value - value < min_diff)
        {
            min_diff = current_b->value - value;
            best_position = position + 1;
        }
		if (value > current_b->value && value - current_b->value < min_diff)
		{
			min_diff = value - current_b->value;
			best_position = position;
		}
        position++;
        current_b = current_b->next;
    }
	
	if (value > max_value)
		return (max_position);  // Vložíme pod najväčšie číslo

	if (value < min_value)
		return (min_position + 1);  // Vložíme nad najmenšie číslo

	// printf("b->size:%d\n", b->size);
	return (best_position);
}

int	calculate_operations(t_stack *a, t_stack *b, int value)
{
	t_node	*current;
	int		pos_a;
	int		pos_b;
	int		operations;

	pos_a = 0;
	current = a->top;
	operations = 100000000;
	while (current->value != value)
	{
		current = current->next;
		pos_a++;
	}
	pos_b = get_best_position_b(b, value);
	// printf("pos_a:%d\n", pos_a);
	// printf("pos_b:%d\n", pos_b);

	if (pos_a <= (a->size / 2) && pos_b <= (b->size / 2))
	{
		if (pos_a > pos_b)
			operations = pos_a;
		else
			operations = pos_b;
	} // Operation rr
	if (pos_a > (a->size / 2) && pos_b > (b->size / 2))
	{
		if (a->size - pos_a > b->size - pos_b)
			operations = a->size - pos_a;
		else
			operations = b->size - pos_b;
	} // Operations rrr
	if (pos_a <= (a->size / 2) && pos_b > (b->size / 2))
		operations = pos_a + (b->size - pos_b);	//ra + rrb
	if (pos_b <= (a->size / 2) && pos_a > (a->size / 2))
		operations = pos_b + (a->size - pos_a);	// Operations rb + rra
	// printf("operations:%d\n", operations);
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
	pos_b = get_best_position_b(b, current->value);
	// printf("execute:\npos_a:%d\n", pos_a);
	// printf("pos_b:%d\n", pos_b);
	if (pos_a <= (a->size / 2) && pos_a == 1)
	{
		sa(a);
		pos_a--;
		write(1, "sa\n", 3);
	}
	// if (pos_a <= (a->size / 2) && pos_b == 1)
	// {
	// 	sb(b);
	// 	pos_b--;
	// }
	if (pos_a <= (a->size / 2) && pos_b <= (b->size / 2))
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b);
			pos_a--;
			pos_b--;
			write(1, "rr\n", 3);
		}
		while (pos_a > 0)
		{
			ra(a);
			pos_a--;
			write(1, "ra\n", 3);
		}
		while (pos_b > 0)
		{
			rb(b);
			pos_b--;
			write(1, "rb\n", 3);
		}
	}
	else if (pos_a > (a->size / 2) && pos_b > (b->size / 2))
	{
		while (pos_a < a->size && pos_b < b->size)
		{
			rrr(a, b);
			pos_a++;
			pos_b++;
			write(1, "rrr\n", 4);
		}
		while (pos_a < a->size)
		{
			rra(a);
			pos_a++;
			write(1, "rra\n", 4);
		}
		while (pos_b < b->size)
		{
			rrb(b);
			pos_b++;
			write(1, "rrb\n", 4);
		}
	}
	else if (pos_a <= (a->size / 2))
	{
		while (pos_a > 0)
		{
			ra(a);
			pos_a--;
			write(1, "ra\n", 3);
		}
	}
	else if (pos_a > (a->size / 2))
	{
		while (pos_a < a->size)
		{
			rra(a);
			pos_a++;
			write(1, "rra\n", 4);
		}
	}
	if (pos_b <= (b->size / 2))
	{
		while (pos_b > 0)
		{
			rb(b);
			pos_b--;
			write(1, "rb\n", 3);
		}
	}
	else if (pos_b > (b->size / 2))
	{
		while (pos_b < b->size)
		{
			rrb(b);
			pos_b++;
			write(1, "rrb\n", 4);
		}
	}
	pb(a, b);
	write(1, "pb\n", 3);
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

void	biggest_to_top(t_stack *stack)
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

	// Presunieme maximum na vrch pomocou `rb` alebo `rrb`
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
