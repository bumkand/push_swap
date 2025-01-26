/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:26:35 by jakand            #+#    #+#             */
/*   Updated: 2025/01/26 20:24:08 by jakand           ###   ########.fr       */
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

int	get_best_position_b(t_stack *b, int value) // myslim si ze tu su zle podmienky
{
	t_node	*current;
	int	position;
	int	max_b;
	int	min_b;

	current = b->top;
	position = 0;

	min_b = current->value;
	max_b = current->value;

	while (current)
	{
		if (min_b > current->value)
			min_b = current->value;
		if (max_b < current->value)
			max_b = current->value;
		current = current->next;
	}
	printf("min: %d max: %d\n", min_b, max_b);

	current = b->top;
	while (current->next)
	{
		// Ak je hodnota väčšia ako max_b, vložíme ju nad max_b
		if (value > max_b && current->value == max_b)
			return (position);
		// Ak je hodnota menšia ako min_b, vložíme ju pod min_b
		if (value < min_b && current->next->value == min_b)
			return (position + 1);
		// Inak nájdeme správnu pozíciu medzi dvomi číslami
		if (current->value > value && current->next->value < value)
			return (position + 1);
		if (current->value < value && current->next->value > value)
			return (position + 1);
		position++;
		printf("[b]%d\n", current->value);
		current = current->next;
	}
	if (current)
		printf("[b]%d\n", current->value);
	// if (value > b->top->value || value < b->bottom->value)
	// 	return (0);
	printf("p:%d\n", position);
	return (position + 1);
}

int	calculate_operations(t_stack *a, t_stack *b, int value)
{
	t_node	*current;
	int	pos_a;
	int	pos_b;
	int	operations;

	pos_a = 0;
	current = a->top;
	while (current->value != value)
	{
		current = current->next;
		pos_a++;
	}
	pos_b = get_best_position_b(b, value);
	printf("pos_a:%d\n", pos_a);
	printf("pos_b:%d\n", pos_b);
	if (pos_a <= (a->size / 2) && pos_b <= (b->size / 2))
		operations = (pos_a > pos_b) ? pos_a : pos_b; // Operation rr
	else if (pos_a > (a->size / 2) && pos_b > (b->size / 2))
		operations = (a->size - pos_a > b->size - pos_b) ? a->size - pos_a : b->size - pos_b; // Operations rrr
	else if (pos_a <= (a->size / 2) && pos_b > (b->size / 2))
		operations = pos_a + (b->size - pos_b); //ra + rrb
	else
		operations = (a->size - pos_a) + pos_b; // Operations rra + rb
	printf("operations:%d\n", operations);
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
	pos_b = get_best_position_b(b, value);
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
			pos_a++;
			pos_b++;
		}
		while (pos_a++ < a->size)
			rra(a);
		while (pos_b++ < b->size)
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
		while (pos_b++ < b->size)
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
	while (current_a)
	{
		printf("%d\n", current_a->value);
		operations = calculate_operations(a, b, current_a->value);
		if (operations < min_operations)
		{
			min_operations = operations;
			best_node = current_a;
		}
		current_a = current_a->next;
	}
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
