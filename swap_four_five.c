/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakand <jakand@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:34:40 by jakand            #+#    #+#             */
/*   Updated: 2025/02/11 19:54:39 by jakand           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_stack *a)
{
	t_node		*current;

	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_min_to_top(t_stack *a)
{
	int			min_num;
	int			num_pos;
	int			position;
	t_node		*current_a;
	t_pos		num;

	min_num = 2147483647;
	num_pos = 0;
	position = 0;
	current_a = a->top;
	while (current_a)
	{
		if (current_a->value < min_num)
		{
			min_num = current_a->value;
			num_pos = position;
		}
		current_a = current_a->next;
		position++;
	}
	num.pos_a = num_pos;
	num.pos_b = 0;
	swap_a(a, &num);
	rot_rev_a(a, &num);
}

void	four_num(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		push_min_to_top(a);
		if (is_sorted_a(a) == 1)
			return ;
		pb(a, b);
		write(1, "pb\n", 3);
		three_num(a);
		pa(a, b);
		write(1, "pa\n", 3);
	}
}

void	five_num(t_stack *a, t_stack *b)
{
	if (a->size == 5)
	{
		push_min_to_top(a);
		if (is_sorted_a(a) == 1)
		{
			return ;
		}
		pb(a, b);
		write(1, "pb\n", 3);
		push_min_to_top(a);
		if (is_sorted_a(a) == 1)
		{
			pa(a, b);
			write(1, "pa\n", 3);
			return ;
		}
		pb(a, b);
		write(1, "pb\n", 3);
		three_num(a);
		pa(a, b);
		write(1, "pa\n", 3);
		pa(a, b);
		write(1, "pa\n", 3);
	}
}
