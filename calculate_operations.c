/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:12:29 by jaandras          #+#    #+#             */
/*   Updated: 2025/02/09 10:51:28 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_position(t_stack *b, int value, t_min_max *min_max,
		int *best_position)
{
	t_node	*current_b;
	int		position;

	current_b = b->top;
	position = 0;
	while (current_b)
	{
		if (current_b->value > value && current_b->value - value < min_max->dif)
		{
			min_max->dif = current_b->value - value;
			*best_position = position + 1;
		}
		if (value > current_b->value && value - current_b->value < min_max->dif)
		{
			min_max->dif = value - current_b->value;
			*best_position = position;
		}
		position++;
		current_b = current_b->next;
	}
	if (value > min_max->max_value)
		return (min_max->max_position);
	if (value < min_max->min_value)
		return (min_max->min_position + 1);
	return (*best_position);
}

void	find_min_max(t_stack *b, t_min_max *min_max, int *position)
{
	t_node	*current_b;

	current_b = b->top;
	min_max->max_value = -2147483648;
	min_max->min_value = 2147483647;
	min_max->max_position = 0;
	min_max->min_position = 0;
	*position = 0;
	while (current_b)
	{
		if (current_b->value > min_max->max_value)
		{
			min_max->max_value = current_b->value;
			min_max->max_position = *position;
		}
		if (current_b->value < min_max->min_value)
		{
			min_max->min_value = current_b->value;
			min_max->min_position = *position;
		}
		(*position)++;
		current_b = current_b->next;
	}
}

int	get_best_position_b(t_stack *b, int value)
{
	t_min_max	min_max;
	int			best_position;
	int			position;

	best_position = 0;
	position = 0;
	min_max.dif = 2147483647;
	find_min_max(b, &min_max, &position);
	return (find_best_position(b, value, &min_max, &best_position));
}

void	operations_counter(int *operations, t_stack *a, t_stack *b, t_pos *data)
{
	if (data->pos_a <= (a->size / 2) && data->pos_b <= (b->size / 2))
	{
		if (data->pos_a > data->pos_b)
			*operations = data->pos_a;
		else
			*operations = data->pos_b;
	}
	if (data->pos_a > (a->size / 2) && data->pos_b > (b->size / 2))
	{
		if (a->size - data->pos_a > b->size - data->pos_b)
			*operations = a->size - data->pos_a;
		else
			*operations = b->size - data->pos_b;
	}
	if (data->pos_a <= (a->size / 2) && data->pos_b > (b->size / 2))
		*operations = data->pos_a + (b->size - data->pos_b);
	if (data->pos_b <= (a->size / 2) && data->pos_a > (a->size / 2))
		*operations = data->pos_b + (a->size - data->pos_a);
	// printf("operations:%d\n", operations);
}

int	calculate_operations(t_stack *a, t_stack *b, int value)
{
	t_node	*current;
	int		pos_a;
	int		pos_b;
	int		operations;
	t_pos	data;

	pos_a = 0;
	current = a->top;
	operations = 100000000;
	while (current->value != value)
	{
		current = current->next;
		pos_a++;
	}
	pos_b = get_best_position_b(b, value);
	data.pos_a = pos_a;
	data.pos_b = pos_b;
	// printf("pos_a:%d\n", pos_a);
	// printf("pos_b:%d\n", pos_b);
	operations_counter(&operations, a, b, &data);
	return (operations);
}
